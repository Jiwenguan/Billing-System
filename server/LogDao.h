#ifndef _LOGDAO_
#define _LOGDAO_
#include"data.h"
class LogDao{
public:
	virtual void insert(const MLogRec& log)=0;
};


#endif  //_LOGDAO_

