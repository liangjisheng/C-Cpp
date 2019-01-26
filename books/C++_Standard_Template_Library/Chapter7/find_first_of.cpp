
/***********************************************************
 * @brief: find_first_of
 * @author: Jisheng Liang
 * @email: 1294851990@qq.com
 * @date: 2017/12/20 15:10:35
 * @version: 1.0
 **********************************************************/

/* 
 find_first_of(b, e, sb, se);
 find_first_of(b, e, sb, se, bp);	使用逆向迭代器，实现find_last_of
*/

/************************************************************************************* 
std::find_first_of()           所有容器适用                                algorithm 
-------------------------------------------------------------------------------------- 
template <class ForwardIterator1, class ForwardIterator2> 
ForwardIterator1 find_first_of ( ForwardIterator1 first1, ForwardIterator1 last1, 
                                 ForwardIterator2 first2, ForwardIterator2 last2 ); 
 
template <class ForwardIterator1, class ForwardIterator2, class BinaryPredicate> 
ForwardIterator1 find_first_of ( ForwardIterator1 first1, ForwardIterator1 last1, 
                                 ForwardIterator2 first2, ForwardIterator2 last2, 
                                 BinaryPredicate pred ); 
 
//eg： 
template<class ForwardIterator1, class ForwardIterator2> 
ForwardIterator1 find_first_of ( ForwardIterator1 first1, ForwardIterator1 last1, 
                                 ForwardIterator2 first2, ForwardIterator2 last2) 
{ 
    for ( ; first1 != last1; ++first1 ) 
        for (ForwardIterator2 it=first2; it!=last2; ++it) 
            if (*it==*first1)          // or: if (comp(*it,*first)) for the pred version 
                return first1; 
    return last1; 
} 
*************************************************************************************/  

#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 不区分大小写
bool comp_case_insensitive(char c1, char c2) { return (tolower(c1) == tolower(c2)); }

void SplitFilename(const string& str);

int main()
{
	int mychars[] = { 'a', 'b', 'c', 'A', 'B', 'C' };
	vector<char> myvector(mychars, mychars + 6);
	vector<char>::iterator it;
	int match[] = { 'A', 'B', 'C' };

	cout << "母串: a b c A B C" << endl;
	cout << "子串：A B C" << endl;

	// using default comparison:
	it = find_first_of(myvector.begin(), myvector.end(), match, match + 3);

	if (it != myvector.end())
		cout << "first match is: " << *it << endl;

	// using predicate comparison:
	it = find_first_of(myvector.begin(), myvector.end(),
						match, match + 3, comp_case_insensitive);

	if (it != myvector.end())
		cout << "first catch is: " << *it << endl;

	// find_fist_of + 逆向迭代器
	vector<char>::reverse_iterator rit;
	rit = find_first_of(myvector.rbegin(), myvector.rend(), match, match + 3);

	if (rit != myvector.rend())
		cout << "last match is: " << *rit << endl;

	cout << endl;

	string str1("/user/bin/man");
	string str2("C:\\Windows\\test.exe");

	SplitFilename(str1);
	cout << endl;
	SplitFilename(str2);

	system("pause");
	return 0;
}

void SplitFilename(const string& str)
{
	size_t found ;
	cout << "Splitting: " << str << endl;
	found = str.find_last_of("\\/");
	cout << " folder: " << str.substr(0, found) << endl;
	cout << " file: " << str.substr(found + 1) << endl;
}
