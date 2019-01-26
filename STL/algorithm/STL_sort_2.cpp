
/***********************************************************
 * @name: STL_sort_2.cpp
 * @brief: sort
 * @author: Jisheng Liang
 * @date: 2018/7/11 17:24:09
 * @version: 1.0
 **********************************************************/

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

//函数模板声明
template<typename Container>
void Display(ostream &out, const Container &c);

//小于模板
template<typename T>
bool LessThan(T a, T b) { return a > b; }

//int小于函数
bool IntLessThan(int a, int b) { return a > b; }

//double小于函数
bool DubLessThan(double a, double b) { return a < b; }


int main()
{
	int ints[] = { 555,33,444,22,222,777,1,66 };
	vector<int> v(ints, ints + 5);
	sort(v.begin(), v.end(), IntLessThan);//默认从小到大，现在从大到小排序
	cout << "Sorted list of integers:" << endl;
	Display(cout, v);
	double dubs[] = { 55.5,3.3,44.4,2.2,22.2,77.7,0.1 };
	vector<double> d(dubs, dubs + 7);
	sort(d.begin(), d.end(), DubLessThan);//从小到大排序
	cout << "Sorted list of doubles:" << endl;
	Display(cout, d);

	getchar();
	return 0;
}

//函数模板定义
template<typename Container>
void Display(ostream &out, const Container &c)
{
	for (Container::size_type i = 0; i < c.size(); i++)
		out << c[i] << " ";
	out << endl;
}
