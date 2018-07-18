#include"StoreThread.h"
extern LogQueue lqueue;
StoreThread::StoreThread(LogDao& dao):m_dao(dao){
	cout<<"构造好存储线程对象"<<endl;	
	start();
}
void* StoreThread::run(void){
	cout<<"StoreThread::run()开始"<<endl;
	MLogRec mrc={0};
	while(1){
		//从链表中取出结构体
		lqueue>>mrc;
		//多态 插入到文件中
		m_dao.insert(mrc);
	}
	delete this;
	cout<<"StoreThread::run()结束"<<endl;
	
}
StoreThread::~StoreThread(){
	cout<<"～StoreThread()"<<endl;
}
