#include"ConsoleSender.h"
	//
void ConsoleSender::sendLog(list<MLogRec> logs)//throw(SendException)
{
	cout<<"在屏幕上输出啦"<<endl;
	for(MIT it=logs.begin();it!=logs.end();++it){
		//cout<<*it<<endl;
	}	
	cout<<"在屏幕上输完啦"<<endl;
}
