#ifndef _EXCEPTION_
#define _EXCEPTION_
#include<iostream>
#include<string>
using namespace std;
class ClientException:public exception{
public:
	ClientException(void):m_msg("发生异常啦"){}
	ClientException(const string &msg):m_msg(msg){}
	~ClientException()throw(){}
	const char* what(void)const throw(){
		cout<<m_msg<<endl;
		return "error occurs..";
	}
private:
	string m_msg;
};
class BackupException:public ClientException{
public:
	~BackupException()throw(){}
	BackupException(void):ClientException("发生备份异常啦"){}
	BackupException(const string& msg):ClientException(msg){}
};

class ReadException:public ClientException{
public:
	~ReadException()throw(){}
	ReadException(void):ClientException("发生读取异常啦"){}
	ReadException(const string& msg):ClientException(msg){}
};
class SaveException:public ClientException{
public:
	~SaveException()throw(){}
	SaveException(void):ClientException("发生保存异常啦"){}
	SaveException(const string& msg):ClientException(msg){}
};
class SendException:public ClientException{
public:
	~SendException()throw(){}
	SendException(void):ClientException("发生发送异常啦"){}
	SendException(const string& msg):ClientException(msg){}
};

class SocketException:public ClientException{
public:
	~SocketException()throw(){}
	SocketException(void):ClientException("发生socket异常啦"){}
	SocketException(const string& msg):ClientException(msg){}
};
#endif // _EXCEPTION

