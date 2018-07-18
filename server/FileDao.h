#ifndef _FILEDAO_
#define _FILEDAO_
#include"LogDao.h"
#include<iostream>
#include<fstream>
#include"data.h"
using namespace std;
class FileDao:public LogDao{
public:
	FileDao(const string& path);
	~FileDao();
	void insert(const MLogRec& log);
private:
	ofstream m_ofs;
};



#endif  //_FILEDAO_
