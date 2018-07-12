
// 统计一个整数序列中数字出现的次数

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <map>

using namespace std;

int main()
{
	srand(time(0));

	int arr[30] = {0};
	int hashTable[30] = {0};
	for(int i = 0; i < 30; i++)
	{
		arr[i] = rand() % 30;
		hashTable[arr[i]]++;
	}

	for(int i = 0; i < 30; i++)
		cout << arr[i] << ' ';
	cout << endl;

	map<int, int> mapRes;
	cout << "number\tcounts\n";
	for(int i = 0; i < 30; i++)		
		mapRes.insert(make_pair(arr[i], hashTable[arr[i]]));

	map<int, int>::iterator iter;
	for(iter = mapRes.begin(); iter != mapRes.end(); iter++)
		cout << iter->first << '\t' << iter->second << endl;

	system("pause");
	return 0;
}