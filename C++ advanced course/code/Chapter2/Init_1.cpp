
#include <iostream>
#include <vld.h>

using std::cout;
using std::endl;

void DispStar(char* &p, int width)
{
	// if(!p || p && p[0] < width + 2)			// 和下面一行的代码等价
	if(!p || (p && p[0] < width + 2))
	{
		delete [] p;
		p = new char[width + 2];
		memset(p, 0, width + 2);
		p[0] = width + 2;
	}

	if(p)
	{
		int i = 0;
		for(i = 1; i <= width; i++)
			p[i] = '*';
		p[i] = '\0';
		cout << p + 1 << endl;
	}
}


int main()
{
	// 如果不初始化为NULL,则会发生内存访问错误
	char *p = NULL;
	for(int i = 0; i < 10; i++)
		DispStar(p, rand() % 20 + 1);

	// delete p;		// 这两行代码都可以释放p,这是什么情况?而且还都没有内存泄露
	delete [] p;
	p = NULL;

	system("pause");
	return 0;
}

