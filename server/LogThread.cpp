#include"LogThread.h"
void LogThread::start(void){
	cout<<"开始创建新线程"<<endl;
	pthread_t ptd;
	//传递给线程过程函数的参数为指向线程(子类)对象的this指针
	int error = pthread_create (&ptd, NULL, run, this);
	// 若失败
	if (error){
		// 记录一般错误日志
		cout<<"创建线程失败"<<endl;
		//throw 
	}
	int i;
	cout<<"线程创建完成"<<endl;
}
//注意这里的格式！！
void* LogThread::run(void * arg){
	cout<<"static LogThread::run(void*)"<<endl;
	return static_cast<LogThread*>(arg)->run();
	//return ((LogThread*)arg)->run();
}

