#include"OracleDao.h"
#include <stdio.h>
#include <string.h>
exec sql include sqlca;
OracleDao::OracleDao(const string& username,const string& password){
	exec sql begin declare section;
		char sqlstr[200];
	exec sql end declare section;
	exec sql connect:string(username+"/"+password).c_str();
	strcpy(sqlstr,"create table dms_zsm_00(\
		id number PRIMARY KEY,\
		logname varchar2(20),\
		logtime date,\
		logouttime date,\
		durations number(12),\
		logip varchar2(20))");
	exec sql execute immediate :sqlstr;
	exec sql commit work release;
}
OracleDao::~OracleDao(){


}
void OracleDao::insert(const MLogRec& log){
	
}
