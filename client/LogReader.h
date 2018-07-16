#ifndef _LOGREADER_
#define _LOGREADER_
#include<list>
#include<string>
#include"excep.h"
#include"data.h"
typedef list<LogRec>::iterator IT;
typedef list<MLogRec>::iterator MIT;
using namespace std;
//
class LogReader{
public:
	//
	LogReader(const string& logFile,const string& loginsFile);
	//
	list<MLogRec> readLog();
private:
	//
	void backup()throw(BackupException);
	//
	void readLoginsFile()throw(ReadException);
	//
	void readBackupFile()throw(ReadException);
	//
	void match();
	//
	void saveLoginsFile()throw(SaveException);
private:
	//
	string m_logFile;
	//
	string m_loginsFile;
	//
	string m_backupFile;
	//
	list<LogRec> m_logins;
	//
	list<LogRec> m_logouts;
	//
	list<MLogRec> m_logs;
};
#endif //_LOGREADER_
