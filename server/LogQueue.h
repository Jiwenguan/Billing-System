#ifndef _LOGQUEUE_
#define _LOGQUEUE_
#include"data.h"
#include<list>
class LogQueue{
public:
	LogQueue();
	LogQueue& operator<<(const MLogRec& log);
	LogQueue& operator>>(MLogRec& log);
	~LogQueue();
private:
	pthread_mutex_t m_mutex;
	pthread_cond_t m_cond;
	list<MLogRec> m_logs;
};

//LogQueue lqueue;
#endif  //_LOGQUEUE_


