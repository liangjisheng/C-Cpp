
// ϵͳ���ύ�����в���ʱ�����Զ�������argv[]�����һ����Ч���������һ����ָ��
// �������ÿ�ָ���ƶϳ����������ж��ٸ�����

#include <iostream>

using std::endl;
using std::cout;

int main(int argc, char* argv[])
{
	int i = 0;
	while(argv[i])
		cout << argv[i++] << endl;
	cout << "argc = " << argc << endl;
	cout << "i = " << i << endl;

	system("pause");
	return 0;
}