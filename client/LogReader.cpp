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
list<MLogRec>& LogReader::readLog(){
	//从m_logFile文件复制一份，名字设为wtfmx.日期,存在m_backupFile，并且把之前文件内容清空
	backup();
/*
	cout<<sizeof(Record)<<endl;
	cout<<sizeof(LogRec)<<endl;
	cout<<sizeof(MLogRec)<<endl;
	cout<<"pid_t: "<<sizeof(pid_t)<<endl;
	cout<<"unsigned long: "<<sizeof(unsigned long)<<endl;
	cout<<"unsigned short: "<<sizeof(unsigned short)<<endl;
*/
	//从m_loginsFile中读取内容，存入m_logins链表
	readLoginsFile();
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
	int fd=open(m_logFile.c_str(),O_RDWR|O_TRUNC);
	close(fd);
	cout<<"备份文件完成"<<endl;
}



//读取上一次未匹配的loginsFile，
void LogReader::readLoginsFile()throw(ReadException)
{
	cout<<"读取登入文件开始"<<endl;
	int fd=open(m_loginsFile.c_str(),O_RDONLY);
	if(fd==-1){
		//throw ReadException();
		return ;
	}
	LogRec rc={0};
	while(1){
		memset(&rc,0,80);	
		int r=read(fd,&rc,80);
		if(r<=0)break;
		//cout<<rc.logname<<","<<rc.logip<<","<<rc.pid<<","<<rc.logtime<<endl;
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
	
	while(1){
		memset(&re,0,sizeof(Record));	
		int r=read(fd,&re,sizeof(Record));
		if(r<=0)break;
		LogRec lns={0};
		if(!strncmp(re.username,".",1)){
			continue;
		}
		//cout<<re.username<<" name,"<<re.pid<<" pid ,"<<re.type<<" type,"<<re.logtime<<" logtime ,"<<re.ip<<" ip ,"<<endl;
		strcpy(lns.logname,re.username);
		lns.pid=re.pid;
		lns.logtime=re.logtime;
		strcpy(lns.logip,re.ip);
		//cout<<lns.logname<<",D"<<lns.pid<<",C"<<lns.logtime<<",B"<<lns.logip<<endl;
		if(re.type==1792){
			m_logins.push_back(lns);
		}else if(re.type==2048){
			m_logouts.push_back(lns);
		}
	}
	cout<<"登入记录条数："<<m_logins.size()<<endl;
	cout<<"登出记录条数："<<m_logouts.size()<<endl;
	cout<<"读取备份文件结束"<<endl;
}
	//
void LogReader::match()
{
	cout<<"进行匹配开始"<<endl;
	for(IT it1=m_logouts.begin();it1!=m_logouts.end();++it1){
		for(IT it2=m_logins.begin();it2!=m_logins.end();++it2){
			if((!strncmp(it1->logname,it2->logname,32))
				  &&(!strncmp(it1->logip,it2->logip,32))
				  &&it1->pid==it2->pid){
				//填充MLogRec结构体
				MLogRec mc={0};
				strncpy(mc.logname,it1->logname,32);
				strncpy(mc.logip,it1->logip,32);
				mc.pid=it1->pid;
				mc.logintime=it2->logtime;
				mc.logouttime=it1->logtime;
				mc.durations=mc.logouttime-mc.logintime;
				//将该结构体插入到链表中
				m_logs.push_back(mc);
				//将m_logins链表中该元素删除
				m_logins.erase(it2);
				//跳出循环
				break;
			}
		}
		//事实证明，并不需要弹出外层的元素，因为后面并没有用到该链表
		//在循环外面将匹配和未匹配的m_logouts的元素删除
		//it1 = m_logouts.erase(it1);//返回下一元素的位置
		//--it1;//避免跳过删除后的下一个元素
	}
	cout<<"匹配成功的条数为："<<m_logs.size()<<endl;
	cout<<"进行匹配结束"<<endl;
}
	//
void LogReader::saveLoginsFile()throw(SaveException)
{
	cout<<"保存未匹配的登入文件开始"<<endl;
	int fd=open(m_loginsFile.c_str(),O_CREAT|O_TRUNC|O_RDWR);
	for(IT it=m_logins.begin();it!=m_logins.end();++it){
		write(fd,(void*)&(*it),sizeof(LogRec));
	}
	close(fd);	
	cout<<"保存未匹配的登入文件结束"<<endl;
}






















