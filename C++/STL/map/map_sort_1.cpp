
/***********************************************************
 * @name: map_sort_1.cpp
 * @brief: map_sort
 * @author: 梁基圣
 * @date: 2018/7/24 14:31:27
 * @version: 1.0
 **********************************************************/

#include <iostream>
#include <map>
#include <string>

using namespace std;

typedef struct tagStudentInfo
{
	int nID;
	string strName;
}StudentInfo, *PStudentInfo;

class mySort
{
public:
	bool operator() (StudentInfo const& _A, StudentInfo const& _B) const
	{
		if (_A.nID < _B.nID)
			return true;
		if (_A.nID == _B.nID)
			return _A.strName.compare(_B.strName) < 0;
		return false;
	}
};


void map_sort()
{
	map<StudentInfo, int, mySort> mapstu;
	map<StudentInfo, int, mySort>::iterator iter;
	StudentInfo studentinfo;
	studentinfo.nID = 2;
	studentinfo.strName = "test";
	mapstu.insert(pair<StudentInfo, int>(studentinfo, 90));
	studentinfo.nID = 1;
	studentinfo.strName = "case";
	mapstu.insert(pair<StudentInfo, int>(studentinfo, 80));

	for (iter = mapstu.begin(); iter != mapstu.end(); iter++)
		cout << iter->first.nID << " " << iter->first.strName << " " << iter->second << endl;
}


int main()
{
	map_sort();

	getchar();
	return 0;
}
