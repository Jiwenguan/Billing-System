#include"SocketSender.h"
  #include <sys/types.h>          /* See NOTES */
       #include <sys/socket.h>
 #include <arpa/inet.h>

//SocketSender的构造函数
SocketSender::SocketSender(const string& failFile,
	short port,const string& ip):
		m_failFile(failFile),m_port(port),m_ip(ip){}
	//
void SocketSender::sendLog(list<MLogRec>& logs){
	try{
		try{
			//读取上次发送失败文件，加入logs链表中
			readFailFile(logs);
		}
		catch(ReadException& ex){
			cout<<"没有上次发送失败文件"<<endl;
		}
		connectServer();
		sendData(logs);
	}	
	catch(SocketException& ex){
		ex.what();
		saveFailFile(logs);
		return ;
	}
	catch(SendException& ex){
		ex.what();
		saveFailFile(logs);
		return ;
	}
	return;
}
	//
void SocketSender::connectServer(){
	cout<<"开始准备连接服务器"<<endl;
	struct sockaddr_in serv;//ipv4地址家族类型的变量
	//创建一个通讯端点
	m_sockfd=socket(AF_INET,SOCK_STREAM,0);
	if(m_sockfd==-1){
		throw SocketException("socket");	
        	return ;
    	}
	//初始化服务器的ip地址和端口号
	serv.sin_family=AF_INET;//使用的地址家族
	serv.sin_port=htons(m_port);    //端口号
 	//ip地址 127.0.0.1
    	inet_pton(AF_INET,m_ip.c_str(),&serv.sin_addr);

    	//向服务器发起连接,就要知道服务器的ip地址和端口号
    	int c=connect(m_sockfd,(struct sockaddr *)&serv,sizeof(serv));
    	if(c==-1){
		throw SocketException("connect");
        	return ;
    	}
	cout<<"连接服务器建立"<<endl;
}
	//
void SocketSender::readFailFile(list<MLogRec>& logs){
	cout<<"读取失败文件开始"<<endl;
	int fd=open(m_failFile.c_str(),O_RDONLY);
	while(1){
		MLogRec lns={0};
		int r=read(fd,&lns,sizeof(MLogRec));
		if(r<=0)break;
		//cout<<lns.logname<<","<<lns.pid<<","<<lns.durations<<","<<lns.logip<<endl;
		logs.push_front(lns);
	}
	close(fd);
	cout<<"现在记录总数为： "<<logs.size()<<endl;
	cout<<"读取失败文件结束"<<endl;

}
	//
void SocketSender::sendData(list<MLogRec>& logs){
	cout<<"开始发送数据"<<endl;
	for(MIT it=logs.begin();it!=logs.end();++it){
		write(m_sockfd,(void*)&(*it),sizeof(MLogRec));
	}
	close(m_sockfd);
	cout<<"发送数据结束，关闭连接"<<endl;	
}
	//
void SocketSender::saveFailFile(list<MLogRec>& logs){
	cout<<"保存发送失败文件开始"<<endl;
	int fd=open(m_failFile.c_str(),O_CREAT|O_TRUNC|O_RDWR);
	for(MIT it=logs.begin();it!=logs.end();++it){
		//cout<<*it<<endl;
		write(fd,(void*)&(*it),sizeof(MLogRec));
	}
	close(fd);	
	cout<<"保存发送失败文件结束"<<endl;

}



























