
// ����Ӻ����ĵ��ô����ݵ���������������쳣�׳��㴫�ݵ�catch�Ӿ��������õ�
// ������ͬ����ֻ�ǲ����������쳣���ݵ������һ�����棬�ڶ����������ں�������
// �߻��׳��쳣���뱻�����߻��쳣������֮�������ƥ��Ĺ��̲�ͬ

#include <iostream>
#include <math.h>

using namespace std;

void throwint()
{
	int i = 5;
	throw i;
}

double Sqrt(double d) { return sqrt(d); }

int main()
{
	int i = 5;
	// int to double
	cout << "sqrt(5) = " << Sqrt(i) << endl;

	try{
		throwint();
	}
	// C++������д�int��double����ʽ����ת���������Sqrt(i)
	// ������catch�Ӿ��ƥ���쳣�����ǲ������������ת��
	// �����catchֻ�ܲ�������Ϊdouble���͵��쳣������������ת��
	// Ҫ�벶��int�쳣������ʹ�ô���int��int&������catch�Ӿ�
	catch(double){
		cout << "catched" << endl;
	}
	catch(...){
		cout << "not catched" << endl;
	}
	
	system("pause");
	return 0;
}