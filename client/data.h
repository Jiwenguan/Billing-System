#ifndef _DATA_
#define _DATA_
struct Record{
	char username[32];
	char idle1[4];
	char idle2[36];
	pid_t pid;
	unsigned short type;
	char idle3[2];
	char idle4[2];
	char idle5[2];
	unsigned long logtime;
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
	long logtime;
};
struct MLogRec{
	char logname[32];
	char logip[32];
	pid_t pid;
	long logintime;
	long logouttime;
	long durations;
	friend ostream& operator<<(ostream& os,MLogRec & mlogrec){
		os<<mlogrec.logname<<","
		  <<mlogrec.pid<<","
		<<mlogrec.logip<<","
		<<mlogrec.logintime<<","
		<<mlogrec.logouttime<<","
		<<mlogrec.durations<<endl;
	}
};

#endif //_DATA_
