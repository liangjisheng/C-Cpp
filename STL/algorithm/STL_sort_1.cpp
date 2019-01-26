
/***********************************************************
 * @name: STL_sort_1.cpp
 * @brief: sort
 * @author: Jisheng Liang
 * @date: 2018/7/11 17:21:01
 * @version: 1.0
 **********************************************************/

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

//栈的小于函数
template<typename Elementtype>
bool operator<(const stack<Elementtype> &s1, const stack<Elementtype> &s2)
{
	return s1.top < s2.top;
}

//Display stack
template<typename Elementtype>
void Display(stack<Elementtype> s);


int main()
{
	vector< stack<int> > s(4);
	s[0].push(10); s[0].push(20);
	s[1].push(30);
	s[2].push(50); s[2].push(60);
	s[3].push(1); s[3].push(2); s[3].push(3);
	sort(s.begin(), s.end());
	for (int i = 0; i < 4; i++) 
	{
		cout << "Stack #" << i << ": ";
		Display(s[i]);
	}

	getchar();
	return 0;
}

template<typename Elementtype>
void Display(stack<Elementtype> s)
{
	while (!s.empty())
	{
		cout << s.top() << " "; 
		s.pop();
	}
	cout << endl;
}
