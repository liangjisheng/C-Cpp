
// ���ݲ����ʹ����쳣���һ�����ǣ�catch�Ӿ�ƥ��˳������ȡ���������ڳ�����
// ���ֵ�˳��.���һ���������쳣���ܱ�����������쳣��catch�Ӿ䲶��,��ʹͬʱ
// �������ܴ�����������쳣��catch�Ӿ�����ͬ��try�����Ӧ

#include <iostream>

using namespace std;

class stuff
{
	int n;
	char c;
public:
	stuff() { n = c = 0; }
};

class SpecialStuff : public stuff
{
	double d;
public:
	SpecialStuff() { d = 0.0; }
};


int main()
{
	SpecialStuff localStuff;
	try{
		throw localStuff;
	}
	catch(stuff &){
		cout << "stuff catched" << endl;
	}
	catch(SpecialStuff&){
		cout << "SpecialStuff catched" << endl;
	}

	system("pause");
	return 0;
}
