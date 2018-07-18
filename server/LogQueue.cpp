#include"LogQueue.h"
LogQueue::LogQueue(){
	cout<<"LogQueue()初始化锁开始"<<endl;
	//初始化一把mutex锁
	pthread_mutex_t m_mutex = PTHREAD_MUTEX_INITIALIZER;
	pthread_cond_t m_cond = PTHREAD_COND_INITIALIZER;
	cout<<"LogQueue()初始化锁结束"<<endl;
}
LogQueue& LogQueue::operator<<(const MLogRec& log){
	cout<<"LogQueue::<<插入开始"<<endl;
        //加锁
        pthread_mutex_lock(&m_mutex);
        //将元素插入链表
        m_logs.push_back(log);

        //解锁
        pthread_mutex_unlock(&m_mutex);

        //通知阻塞等待队列不空的线程
        pthread_cond_signal(&m_cond);
	cout<<"LogQueue::<<插入结束"<<endl;
}
LogQueue& LogQueue::operator>>( MLogRec& log){
	typedef list<MLogRec>::iterator MIT;
	cout<<"LogQueue::>>取出开始"<<endl;
        //加锁
        pthread_mutex_lock(&m_mutex);
        if(m_logs.empty()){
		//阻塞等待链表不为空
		cout<<"正在阻塞等待链表不为空"<<endl;
        	pthread_cond_wait(&m_cond,&m_mutex);
	}
	MIT it=m_logs.begin();
	log=*it;
	m_logs.erase(it);
        //解锁
        pthread_mutex_unlock(&m_mutex);
	cout<<"LogQueue::>>取出结束"<<endl;
	return *this;
}
LogQueue::~LogQueue(){
	cout<<"销毁条件变量"<<endl;
	// 销毁条件变量
	pthread_cond_destroy (&m_cond);
	// 销毁互斥锁
	pthread_mutex_destroy (&m_mutex);
}

