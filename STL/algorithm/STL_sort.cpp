
/***********************************************************
 * @name: STL_sort.cpp
 * @brief: sort
 * @author: Jisheng Liang
 * @date: 2018/7/11 17:18:28
 * @version: 1.0
 **********************************************************/

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

template<typename Container>
void Display(ostream &out, const Container &c);


int main()
{
	int ints[] = { 555,33,444,22,222,777,1,66 };
	vector<int> v(ints, ints + 5);
	sort(v.begin(), v.end());
	cout << "Sorted list of integers:" << endl;
	Display(cout, v);
	double dubs[] = { 55.5,3.3,44.4,2.2,22.2,77.7,0.1 };
	vector<double> d(dubs, dubs + 7);
	sort(d.begin(), d.end());
	cout << "Sorted list of doubles:" << endl;
	Display(cout, d);

	getchar();
	return 0;
}

template<typename Container>
void Display(ostream &out, const Container &c)
{
	for (Container::size_type i = 0; i < c.size(); i++)
		out << c[i] << " ";
	out << endl;
}
