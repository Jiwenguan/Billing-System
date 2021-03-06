#ifndef _DATA_
#define _DATA_
struct Record{
	char username[32];
	char idle1[4];
	char idle2[32];
	//pid_t pid;
	char idle10[2];
	unsigned short pid;
	unsigned short type;
	char idle3[2];
	char idle4[2];
	char idle5[2];
	unsigned int logtime;
	char idle6[4];
	char idle7[4];
	char idle8[20];
	unsigned short rlen;
	char ip[257];
};



struct LogRec{
	char logname[32];
	char logip[32];
	pid_t pid;
	unsigned int logtime;
};
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
