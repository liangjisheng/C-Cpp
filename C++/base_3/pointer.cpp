
#include <iostream>

using namespace std;

void testNew(char **lpsz)
{
	int nLen = 10;
	*lpsz = new char[nLen];
	memset(*lpsz, 0, nLen);
	char *lpsz1 = "test";
	memcpy(*lpsz, lpsz1, strlen(lpsz1) * sizeof(char));
	cout << *lpsz << endl;
}

void test2(char *&lpsz)
{
	int nLen = 10;
	lpsz = new char[nLen];
	memset(lpsz, 0, nLen);
	char *lpsz1 = "test";
	memcpy(lpsz, lpsz1, strlen(lpsz1) * sizeof(char));
	cout << lpsz << endl;
}

// 这个函数由于是值传递指针，因此会造成内存泄露，在这个函数里面分配的内存没有释放
void test3(char *lpsz)
{
	cout << &lpsz << endl;
	int nLen = 10;
	lpsz = new char[nLen];
	memset(lpsz, 0, nLen);
	char *lpsz1 = "test";
	memcpy(lpsz, lpsz1, strlen(lpsz1) * sizeof(char));
	cout << lpsz << endl;
}

int main() 
{
	char *lpsz = NULL;
	testNew(&lpsz);
	cout << lpsz << endl;
	delete [] lpsz;
	lpsz = NULL;

	test2(lpsz);
	cout << lpsz << endl;
	delete [] lpsz;
	lpsz = NULL;

	test3(lpsz);
	cout << &lpsz << endl;
	// cout << lpsz << endl;
	delete [] lpsz;
	lpsz = NULL;

	char *lpszP = new char(4);
	cout << lpszP << endl;
	delete lpszP;

	char *lpszP1 = new char[1];
	*lpszP1 = 'c';
	cout << lpszP1 << endl;
	delete [] lpszP1;

	system("pause");
	return 0;
}
