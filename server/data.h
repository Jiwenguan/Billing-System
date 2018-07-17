#ifndef _DATA_
#define _DATA_
#include<iostream>

using namespace std;
struct MLogRec{
	char logname[32];
	char logip[32];
	pid_t pid;
	unsigned int logintime;
	unsigned int logouttime;
	unsigned int durations;
	friend ostream& operator<<(ostream& os,MLogRec & mlogrec){
		os<<"编号:"<<mlogrec.logname<<",pid: "
		  <<mlogrec.pid<<",ip: "
		<<mlogrec.logip<<",登入时间： "
		<<mlogrec.logintime<<",登出时间： "
		<<mlogrec.logouttime<<",在线时长： "
		<<mlogrec.durations<<endl;
	}
};

#endif //_DATA_
