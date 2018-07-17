#ifndef _LOGSENDER_
#define _LOGSENDER_
#include"excep.h"
#include"data.h"
#include<list>
#include"LogReader.h"
//是一个接口
class LogSender{
public:
	//纯虚函数
	virtual void sendLog(list<MLogRec>& logs)=0;	
};
#endif //_LOGSENDER_
