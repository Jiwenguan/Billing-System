#ifndef _SOCKETSENDER_
#define _SOCKETSENDER_
#include"LogSender.h"
#include"LogReader.h"
#include"excep.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<string>
class SocketSender:public LogSender{
public:
	//
	SocketSender(const string& failFile,
		short port,const string& ip);
	//
	virtual void sendLog(list<MLogRec>& logs);
private:
	//
	void connectServer();
	//
	void readFailFile(list<MLogRec>& logs);
	//
	void sendData(list<MLogRec>& logs);
	//
	void saveFailFile(list<MLogRec>& logs);
private:
	//
	string m_failFile;
	//
	short m_port;
	//
	string m_ip;
	//
	int m_sockfd;
};
#endif //_SOCKETSENDER_
