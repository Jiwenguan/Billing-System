#ifndef _CLIENTTHREAD_
#define _CLIENTTHREAD_
#include<iostream>
using namespace std;
#include"LogQueue.h"
#include"LogThread.h"
#include"data.h"
#include <unistd.h>

class ClientThread:public LogThread{
public:
	ClientThread(int connfd);
	//重写run函数
	void* run(void);	
	~ClientThread();
private:
	int m_connfd;
};
#endif //_CLIENTTHREAD_
