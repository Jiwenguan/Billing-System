#include<iostream>
#include"Server.h"
#include"LogQueue.h"
#include"FileDao.h"
#include"LogThread.h"
#include"ClientThread.h"
#include"StoreThread.h"
#include"data.h"
#include"ServerSocket.h"
#include"excep.h"
#include"LogDao.h"
using namespace std;
LogQueue lqueue;
int main(){
	FileDao logFile("./log.dat");
	Server serm(logFile,8080,"127.0.0.1");
	serm.dataMine();
	return 0;
}
