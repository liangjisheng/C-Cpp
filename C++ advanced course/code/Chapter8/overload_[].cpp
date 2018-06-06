
// []��C++�е��±������,�����������ָ����˵���±��������������ȷ����
// ���ܹ��������أ�C++�涨:[]ֻ����Ϊ��ĳ�Ա������������

#include <iostream>
#include <string>

using namespace std;

class A
{
	int num[3];
public:
	A();
	int& operator[](int);
};

A::A()
{
	num[0] = 0;
	num[1] = 1;
	num[2] = 2;
}

// ��������Ϊ��������,�����봫ͳ�������±����㱣��һ�µ�����
// ͨ���±��ҵ��ض�������Ԫ�غ�,���ܶ�,Ҳ��д
int& A::operator[](int sub)
{
	if(sub < 0 || sub > 2)
		throw sub;
	else
		return num[sub];
}


// һ����˵���±���������������ͣ�����C/C++�������±�Ļ����÷�������
// �﷨�ĽǶ���˵����operator[]�������������أ���û���޶��±����������
// ������ĳЩ��������£����Բ���������������͵��±�
class Empolyee
{
	string name;
	string position;
public:
	Empolyee(string, string);
	string& operator[](string);
};

Empolyee::Empolyee(string n, string p)
{
	name = n;
	position = p;
}

// operator[]ֻ����һ������,û�в������߶���һ������������ɱ������
// ���������Ϳ����ǰ���int���ڵ���������,Ӧ���Ƿ�����������,��������
// ������д
string& Empolyee::operator[](string s)
{
	if(s == "name")
		return name;
	else if(s == "position")
		return position;
	throw s;
}


int main()
{
	//A a;
	//A *p = &a;
	//try{
	//	// �ڱ��ʽp[0][i]��,��һ��[]��������±��������Ը��,p[0]�൱��
	//	// *p,����ָ����ָ�Ķ���,���ڶ���[]�����ʹ�õ������غ������,��
	//	// ʾ�Ӷ����ڲ��ĳ�Ա������ȡ����,���±�Ϊ3ʱ,�׳��쳣
	//	for(int i = 0; i <= 4; i++)
	//		cout << p[0][i] << endl;
	//}
	//catch(int sub){
	//	cout << "Subscript out of range:" << sub << endl;
	//}

	Empolyee a("name1", "emp1"), b("name2", "emp2");
	try{
		cout << "A's name is: " << a["name"] << endl;
		cout << "A's position is: " << a["position"] << endl;
		cout << "B's name is: " << b["name"] << endl;
		cout << "B's position is: " << b["position"] << endl;
		cout << "B's address is: " << b["address"] << endl;
	}
	catch(string &s){
		cout << "Unknown attribute: " << s << endl;
	}

	system("pause");
	return 0;
}

