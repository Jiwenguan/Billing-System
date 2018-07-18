#include"Server.h"
Server::Server(LogDao& dao,short port,const string ip):
	m_store(dao),m_socket(port,ip){
	cout<<"初始化了m_store,m_socket两个对象"<<endl;
	//构造函数中初始化了两个对象
	//m_store是一个存储线程
	//m_socket是一个网络连接对象
}
void Server::dataMine(void){
	//cout<<"开启存储线程"<<endl;
	
	m_store.start();//开启存储线程
	m_socket.acceptClient();
	while(1);
	return ;

}
