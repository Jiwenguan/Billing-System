#include"ServerSocket.h"
typedef sockaddr_in SA4;
typedef sockaddr SA;
ServerSocket::ServerSocket(short port,const string ip){
	cout<<"准备开启监听模式"<<endl;
	m_sockfd=socket(AF_INET,SOCK_STREAM,0);
	if(m_sockfd==-1){
		//print failed message;
		cout<<"socket失败"<<endl;		
	}
	
	SA4 addrS;
	addrS.sin_family=AF_INET;
	addrS.sin_port=htons(port);
	addrS.sin_addr.s_addr=htonl(INADDR_ANY);
	//绑定
	if(bind(m_sockfd,(SA*)&addrS,sizeof(addrS))==-1){
		//errori
		cout<<"绑定失败"<<endl;
		//throw
	}
	//listen for connection on a socket
	if(listen(m_sockfd,10)==-1){
		cout<<"监听失败"<<endl;
		//throw
	}
	//准备接受客户端发来的请求
	acceptClient();
}
void ServerSocket::acceptClient(void){
	cout<<"acceptClient()开始"<<endl;
	while(1){
		int cfd=accept(m_sockfd,NULL,0);
		if(cfd==-1){
			cout<<"获取未决连接失败"<<endl;	
			continue;
		}
		cout<<"与客户端建立连接"<<endl;
		ClientThread cthread(cfd);
		cout<<"子进程启动"<<endl;
		cthread.start();
	}	
	//
}
