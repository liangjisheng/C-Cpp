#include"iostream"
#include"tchar.h"
#include"vector"
#include"algorithm"
using namespace std;

// 定义一个函数对象类
class AverageData{
private:
	double m_nTotal;
	int m_nCount;
public:
	AverageData(int nCount=0,double nTotal=0)
		: m_nCount(nCount),m_nTotal(nTotal) {}
	void operator() (int data) {
		m_nTotal+=data;
		m_nCount++;
	}
	// 定义下面的成员函数，可使此对象隐式转换成double类型变量
	// 直接返回计算结果
	operator double() { return GetAverageData(); }
	double GetAverageData() {
		if(m_nCount!=0)
			return m_nTotal/(double)m_nCount;
	}
	int GetCount() { return m_nCount; }
	int GetTotal() { return m_nTotal; }
};

int _tmain(int argc,_TCHAR* argv[])
{
	AverageData ad;	// 创建函数对象
	vector<int> vec;
	vec.push_back(6);
	vec.push_back(9);
	vec.push_back(78);
	vec.push_back(60);
	vec.push_back(63);
	vec.push_back(45);
	vec.push_back(234);
	vec.push_back(1);

	// for_each()返回函数对象，将操作结果存放到函数对象属性中
	ad=for_each(vec.begin(),vec.end(),ad);
	cout<<"count="<<ad.GetCount()<<endl
		<<"Average="<<ad.GetAverageData()<<endl;

	double re=for_each(vec.begin(),vec.end(),ad);
	cout<<re<<endl;

	system("pause");
	return 0;
}

// STL中的函数对象
// 算术操作 plus,minus,multiplies,divides,modules,negate
// 比较操作 equal_to,not_equal_to,greater,less,greater_equal,less_equal
// 逻辑操作 logical_and,logical_or,logical_not