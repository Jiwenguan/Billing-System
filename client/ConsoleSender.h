#include"LogSender.h"
#include"data.h"
#include<list>

class ConsoleSender:public LogSender{
public:
	//
	void sendLog(list<MLogRec> logs);//throw(SendException);
};
