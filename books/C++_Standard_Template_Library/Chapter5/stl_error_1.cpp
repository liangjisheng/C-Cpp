
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	vector<int> coll1;
	vector<int> coll2;

	// runtime error
	vector<int>::iterator iter1 = coll1.begin();
	vector<int>::iterator iter2 = coll1.end();

	if(iter1 == iter2)
		cout << "empty coll.begin() == coll.end()" << endl;
	else
		cout << "empty coll.begin() != coll.end()" << endl;

	system("pause");
	return 0;
}