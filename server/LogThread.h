#ifndef _LOGTHREAD_
#define _LOGTHREAD_
#include<iostream>
#include<pthread.h>
using namespace std;
class LogThread{
public:
	void start(void);
	virtual void* run(void){cout<<"我被调用啦"<<endl;}
	virtual ~LogThread(){}
private:
	//注意这里的格式！！！
	static void* run(void * arg);
};
#endif //_LOGTHREAD_

