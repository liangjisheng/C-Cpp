
/***********************************************************
 * @name: map_sort.cpp
 * @brief: map_sort
 * @author: 梁基圣
 * @date: 2018/7/24 14:21:36
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
	bool operator <(tagStudentInfo const& _A) const
	{
		//这个函数指定排序策略,按nID排序,如果nID相等的话,按strName排序
		if (nID < _A.nID)
			return true;
		if (nID == _A.nID)
			return strName.compare(_A.strName) < 0;
		return false;
	}
}StudentInfo, *PStudentInfo;

void map_sort()
{
	int nSize;
	map<StudentInfo, int> mapstu;
	map<StudentInfo, int>::iterator iter;
	StudentInfo studentinfo;
	studentinfo.nID = 2;
	studentinfo.strName = "test";
	mapstu.insert(pair<StudentInfo, int>(studentinfo, 90));
	studentinfo.nID = 1;
	studentinfo.strName = "tone";
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
