#ifndef _SERVER_
#define _SERVER_
#include"StoreThread.h"
#include"ServerSocket.h"
#include"LogDao.h"
#include"LogQueue.h"
#include<iostream>
using namespace std;

class Server{
public:
	Server(LogDao& dao,short port,const string ip);
	void dataMine();
private:
	StoreThread m_store;
	ServerSocket m_socket;
};

#endif  //_SERVER_


