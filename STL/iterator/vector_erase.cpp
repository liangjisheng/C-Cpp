
#include <iostream>
#include <vector>
#include <list>

using namespace std;

int main()
{
	vector<int> vecint;
	vecint.push_back(1);
	vecint.push_back(1);
	vecint.push_back(2);
	vecint.push_back(2);
	vecint.push_back(3);
	vecint.push_back(4);
	vecint.push_back(5);

	for (size_t i = 0; i < vecint.size(); ++i)
		cout << vecint[i] << ' ';
	cout << endl;

	int n = 2;
	vector<int>::iterator iter1;
	vector<int>::iterator iter = vecint.begin();
	for (; iter != vecint.end(); ++iter)
	{
		if (*iter == n)
		{
			iter1 = vecint.erase(iter);
			iter = iter1;
			--iter;
		}
	}

	for (size_t i = 0; i < vecint.size(); ++i)
		cout << vecint[i] << ' ';
	cout << endl;

	getchar();
	return 0;
}
