#ifndef _STORETHREAD_
#define _STORETHREAD_
#include"LogThread.h"
#include"LogDao.h"
#include"FileDao.h"
#include"LogQueue.h"
#include"data.h"
#include<iostream>
using namespace std;
class StoreThread:public LogThread {
public:
	StoreThread(LogDao& dao);
	void* run(void);
	~StoreThread();
private:	
	LogDao& m_dao;
};
#endif //_STORETHREAD_
