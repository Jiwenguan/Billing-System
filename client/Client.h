#ifndef _CLIENT_
#define _CLIENT_
#include"LogReader.h"
#include"LogSender.h"
#include"excep.h"

using namespace std;
class Client{
public:
	~Client()throw(){}
	Client(LogReader& reader,LogSender& sender);
	void dataMine();//throw(ClientException);
private:
	LogReader& m_reader;
	LogSender& m_sender;
};
#endif //_CLIENT_
