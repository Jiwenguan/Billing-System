#include"FileDao.h"
FileDao::FileDao(const string& path):m_ofs(path.c_str()){
	cout<<"打开文件流"<<endl;
}
FileDao::~FileDao(){
	cout<<"关闭文件流"<<endl;
	//关闭文件输出流	
	m_ofs.close();
}
void FileDao::insert(const MLogRec& log){
	m_ofs<<log;
	//cout<<log;
}

