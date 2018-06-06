
#include <iostream>

using std::cout;
using std::endl;

// goto语句只能跳到同一个函数体内的标号出，跳到其它函数体内是没有任何意义的

void test1()
{
	int a[2][3][4] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	int i, j, k, order = 0;

	for(i = 0; i < 2; i++)
	{
		for(j = 0; j < 3; j++)
		{
			for(k = 0; k < 4; k++)
				cout << a[i][j][k] << " ";
			cout << endl;
		}
		cout << endl;
	}
	cout << endl;


	for(k = 0; k < 4; k++)
	{
		for(i = 0; i < 2; i++)
		{
			for(j = 0; j < 3; j++)
				cout << a[i][j][k] << " ";
			cout << endl;
		}
		cout << endl;
	}

	for(i = 0; i < 2; i++)
	{
		for(j = 0; j < 3; j++)
		{
			for(k = 0; k < 4; k++)
			{
				order++;
				if(8 == a[i][j][k])
					goto disp;
				// cout << a[i][j][k] << " ";
				// cout << endl;
			}			
		}
		// cout << endl;
	}

disp:
	cout << order << endl;
}


// 如果不使用goto，则跳出多个循环需要用多个break
void test2()
{
	// 先跳出k那层，在跳出j那层，最后跳出i那层
	int a[2][3][4] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	int i, j, k, order = 0;
	bool bOut = false;

	for(i = 0; i < 2; i++)
	{
		if(bOut)
			break;
		for(j = 0; j < 3; j++)
		{
			if(bOut)
				break;
			for(k = 0; k < 4; k++)
			{
				order++;
				if(8 == a[i][j][k])
				{
					bOut = true;
					break;
				}
			}
		}
	}

	cout << order << endl;
}


int main()
{
	test1();
	test2();

	system("pause");
	return 0;
}