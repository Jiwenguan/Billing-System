#include"LogDao.h"
#include"data.h"
class OracleDao:public:LogDao{
public:
	OracleDao(const string& username,const string& password);
	~OracleDao();
	void insert(const MLogRec& log);
};
