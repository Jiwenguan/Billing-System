#include"SocketSender.h"

//SocketSender的构造函数
SocketSender::SocketSender(const string& failFile,
	short port,const string& ip):
		m_failFile(failFile),m_port(port),m_ip(ip){}
	//
void SocketSender::sendLog(list<MLogRec>& logs){}
	//
void SocketSender::connectServer(){}
	//
void SocketSender::readFailFile(list<MLogRec>& logs){}
	//
void SocketSender::sendData(list<MLogRec>& logs){}
	//
void SocketSender::saveFailFile(list<MLogRec>& logs){}
