
#include <iostream>
#include <string>
#include <conio.h>

using namespace std;

// _getch()��_getche()�⺯��������ʵ�ֲ�����������룬��Ϊ��������
// ����Ҳ����������������κθ�ʽ�����������Բ�������������������
// �����ַ����е�

int main()
{
	char c[7] = {0};
	cout << "Please input password:";
	int nIndex = 0;
	while(nIndex < 6)
	{
		// ÿ����һ���ַ����������������ڴ棬�����ڱ�׼����豸�ϲ���
		// �л����ַ�
		char tmp = _getch();
		if((tmp > 'a' && tmp < 'z') 
			|| (tmp > 'A' && tmp < 'Z') 
			|| (tmp > '0' && tmp < '9'))
		{
			c[nIndex++] = tmp;
			cout << '*';
		}
	}
	//for(int i = 0; i < 6; i++)
	//{
	//	c[i] = _getch();
	//	cout << '*';
	//}
	cout << endl;
	
	if(string(c) == "123456")
		cout << "right" << endl;
	else
		cout << "wrong" << endl;

	system("pause");
	return 0;
}