#ifndef _SERVERSOCKET_
#define _SERVERSOCKET_
#include"ClientThread.h"
#include<string>
#include<iostream>
#include<string>
#include <sys/types.h>
#include <sys/socket.h>
 #include <arpa/inet.h>

using namespace std;
class ServerSocket{
public:
	ServerSocket(short port,const string ip);
	void acceptClient(void);
private:
	int m_sockfd;
};
#endif //_SERVERSOCKET_

