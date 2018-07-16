
#include"Client.h"

//Client的构造函数
Client::Client(LogReader& reader,LogSender& sender):\
	m_reader(reader),m_sender(sender){}

//Client类的数据挖掘函数
void Client::dataMine(void)//throw(ClientException)
{
	//
	m_sender.sendLog(m_reader.readLog());	
}

