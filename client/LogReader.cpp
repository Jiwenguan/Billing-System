#include<time.h>
#include<stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include<string.h>
#include"LogReader.h"

	//
LogReader::LogReader(const string& logFile,const string& loginsFile):
	m_logFile(logFile),m_loginsFile(loginsFile){}
	//
list<MLogRec> LogReader::readLog(){
	//从m_logFile文件复制一份，名字设为wtfmx.日期,存在m_backupFile，并且把之前文件内容清空
	backup();
	cout<<sizeof(Record)<<endl;
	cout<<sizeof(LogRec)<<endl;
	cout<<sizeof(MLogRec)<<endl;
	//从m_loginsFile中读取内容，存入m_logins链表
	//readLoginsFile();
	//从备份文件m_backupFile中读取内容,存入m_logins链表和m_logouts链表中
	readBackupFile();
	//接下来将两个链表中内容进行匹配，登出在外层循环，登入在内层循环，不匹配的登出将舍弃掉
	match();
	//把不匹配的登入存入m_loginsFile
	saveLoginsFile();
	return m_logs;
}
	//
void LogReader::backup()throw(BackupException)
{
	cout<<"备份文件开始"<<endl;
	//获取系统时间
	char buf[32]={0};
	time_t tt=time(NULL);
	strftime(buf,32,"%Y%m%d%H%M%S",localtime(&tt));
	//	
	m_backupFile=m_logFile+"."+string(buf);
	cout<<m_backupFile<<endl;

	//拼凑系统指令进行复制
	string commond="cp "+m_logFile+" "+m_backupFile;
	system(commond.c_str());
	//清空m_logFile的内容
	int fd=open(m_logFile.c_str(),O_TRUNC);
	close(fd);
	cout<<"备份文件完成"<<endl;
}
	//
void LogReader::readLoginsFile()throw(ReadException)
{
	cout<<"读取登入文件开始"<<endl;
	int fd=open(m_loginsFile.c_str(),O_RDONLY);
	if(fd==-1){
		throw ReadException();
	}
	LogRec rc={0};
	while(1){
		memset(&rc,0,80);	
		int r=read(fd,&rc,80);
		if(r<=0)break;
		cout<<rc.logname<<","<<rc.logip<<","<<rc.pid<<","<<rc.logtime<<endl;
		m_logins.push_back(rc);
	}	
	close(fd);
	cout<<"读取登入文件结束"<<endl;
}
//
void LogReader::readBackupFile()throw(ReadException)
{
	cout<<"读取备份文件开始"<<endl;
	int fd=open(m_backupFile.c_str(),O_RDONLY);
	Record re={0};
	int count=0;
		int r=read(fd,&re,372);
		cout<<re.username<<" name,"<<re.pid<<" pid ,"<<re.type<<" type,"
			<<re.logtime<<" logtime ,"<<re.rlen<<"rlen ,"<<re.ip<<" ip ,"<<endl;
	/*
	while(1){
		memset(&re,0,372);	
		int r=read(fd,&re,372);
		if(r<=0)break;
		LogRec lns;
		if(strncmp(re.username,".",1)){
			continue;
		}
		count++;
		strncmp(lns.logname,re.username,32);
		lns.logname[31]='\0';
		lns.pid=re.pid;
		lns.logtime=re.logtime;
		strncmp(lns.logip,re.ip,re.rlen);
		lns.logip[re.rlen]='\0';
		//cout<<lns.logname<<",D"<<(int)lns.pid<<",C"<<lns.logtime<<",B"<<lns.logip<<endl;
	}*/
	cout<<count<<endl;
	cout<<"读取备份文件结束"<<endl;
}
	//
void LogReader::match()
{
	cout<<"进行匹配开始"<<endl;
	for(IT it1=m_logouts.begin();it1!=m_logouts.end();++it1){
		for(IT it2=m_logins.begin();it2!=m_logins;++it2){
			if()
		}
	
	}
	cout<<"进行匹配结束"<<endl;
}
	//
void LogReader::saveLoginsFile()throw(SaveException)
{
	cout<<"保存未匹配的登入文件开始"<<endl;
	cout<<"保存未匹配的登入文件结束"<<endl;
}
