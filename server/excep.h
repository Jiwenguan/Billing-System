#ifndef _EXCEP_
#define _EXCEP_
#include<iostream>
using namespace std;

class ServerException{
public:
	ServerException():m_msg("发生错误啦"){}
	ServerException(const string msg):m_msg(msg){}
	~ServerException()throw(){}
	const char* what(void){
		cout<<m_msg<<endl;
	}
private:
	string m_msg;
};
class SocketException:public ServerException{
public:
	SocketException():ServerException(){}
	SocketException(const string msg):ServerException(msg){}
};
class DBException:public ServerException{
public:
	DBException():ServerException(){}
	DBException(const string msg):ServerException(msg){}
};
class ThreadException:public ServerException{
public:
	ThreadException():ServerException(){}
	ThreadException(const string msg):ServerException(msg){}
};
#endif //_EXCEP_
