
#include <iostream>
#include <vld.h>

using std::cout;
using std::endl;

void DispStar(char* &p, int width)
{
	// if(!p || p && p[0] < width + 2)			// ������һ�еĴ���ȼ�
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
	// �������ʼ��ΪNULL,��ᷢ���ڴ���ʴ���
	char *p = NULL;
	for(int i = 0; i < 10; i++)
		DispStar(p, rand() % 20 + 1);

	// delete p;		// �����д��붼�����ͷ�p,����ʲô���?���һ���û���ڴ�й¶
	delete [] p;
	p = NULL;

	system("pause");
	return 0;
}

