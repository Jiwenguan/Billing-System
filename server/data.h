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
	friend ostream& operator<<(ostream& os,const MLogRec & mlogrec){
		os<<"logname:"<<mlogrec.logname<<",pid:"
		  <<mlogrec.pid<<",ip:"
		<<mlogrec.logip<<",logintime:"
		<<mlogrec.logintime<<",logouttime: "
		<<mlogrec.logouttime<<",durations: "
		<<mlogrec.durations<<endl;
	}
};

#endif //_DATA_
