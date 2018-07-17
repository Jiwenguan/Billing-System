#include"ClientThread.h"
extern LogQueue lqueue;
ClientThread::ClientThread(int connfd):m_connfd(connfd){
	cout<<"ClientThread线程初始化"<<endl;
}
void* ClientThread::run(void){
	cout<<"ClientThread::run()开始"<<endl;
	MLogRec mrc={0};
	while(1){
		int r=read(m_connfd,&mrc,sizeof(MLogRec));
		if(r<=0)break;
		lqueue<<mrc;
	}
	cout<<"ClientThread::run()结束"<<endl;
	return NULL;
}	
ClientThread::~ClientThread(){
	close(m_connfd);
}
