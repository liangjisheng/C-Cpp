
// ֻ�ܽ�operator<<()����ΪsomeClass�����Ԫ��ʽ����ʱ�����������������������ʽ֮һ
// ostream& operator<<(ostream&, const someClass&);
// ostream& operator<<(ostream&, someClass&);
// ostream& operator<<(ostream&, someClass);
// ��һ����ã�Ҳ��ã����ֺ������ؼȰ�ȫ�и�Ч
// �������������Ҳֻ������Ԫ��������
// istream& operator>>(istream&, someClass&);

#include <iostream>

using namespace std;

class MyComplex
{
	double real;
	double image;
public:
	MyComplex(double r = 0.0, double i = 0.0)
	{
		real = r;
		image = i;
	}
	friend ostream& operator<<(ostream&, const MyComplex&);
	friend istream& operator>>(istream&, MyComplex&);
};


ostream& operator<<(ostream& os, const MyComplex& src)
{
	os << src.real << "+" << src.image << "i";
	return os;
}

istream& operator>>(istream& in, MyComplex& dest)
{
	// ��ʽ������Ҫ����һЩ����Ϊ���������������δ֪�ģ��û����������ݵ�
	// �����п��ܻ����Υ��Լ������Ϊ�������ڸ�ʽ�����뺯����ͨ��Ҫ����
	// һЩ�ݴ�Ĵ���
	bool success = false;
	char ch = '\0';
	while(!success)
	{
		cout << "Please input a complex:";
		in >> dest.real;
		in >> ch;
		if(ch != '+')
			continue;
		in >> dest.image;
		in >> ch;
		if(ch != 'i')
			continue;
		else
			success = true;
	}

	return in;
}

int main()
{
	MyComplex c;
	cin >> c;
	cout << c << endl;

	system("pause");
	return 0;
}
