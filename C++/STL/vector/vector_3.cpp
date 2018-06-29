#include"stdafx.h"
#include"iostream"
#include"vector"
#include"algorithm"
#include"functional"
#include"tchar.h"
using namespace std;

int _tmain(int argc,_TCHAR* argv[])
{
	vector<int> vecSalary;
	cout<<"输入工资数据，0表示结束"<<endl;
	int nSalary=0;
	while(1) {
		cin>>nSalary;
		if(nSalary==0) break;
		vecSalary.push_back(nSalary);
	}
	// 使用count_if统计vecSalary容器中大于1000的元素个数
	int nTotal=count_if(vecSalary.begin(),vecSalary.end(),
		bind2nd(greater<int>(),1000));
	cout<<"工资超过1000的员工数量为:"<<nTotal<<endl;

	system("pause");
	return 0;
}