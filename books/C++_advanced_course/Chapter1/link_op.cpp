
// ��ʽ�����ص�����һ������г���������������������ͬ�Ĳ�����
// ��ʽ��ֵ�����������ҽ���ɼ�a = b = c;����Ϊa = (b = c);
// ����ʽ����������������ɣ���cout << a << b ����Ϊ(cout << a) << b;
// ���Ҫ���������͵���ʽ�����������������غ���һ�����ܷ���void����
// ����void��ֹ����ʽ�����Ŀ�����
// ��������������ô��ʽ������Ҫ�����ڸ��ƹ��캯��������������
// ���б�д��ȷ�ĸ��ƹ��캯��

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
	MyComplex(const MyComplex& src)
	{
		cout << "Copy Constructor" << endl;
		real = src.real;
		image = src.image;
	}
	void Show() const
	{
		cout << real << " + " << image << "i" << endl;
	}

	MyComplex operator = (const MyComplex& src);
};


MyComplex MyComplex::operator=(const MyComplex& src)
{
	real = src.real;
	image = src.image;
	return src;					// ������������ʱ���󣬻���ø��ƹ��캯������ɽϴ���
}


// �����ֵ��������ض�������ã��Ͳ��������ĸ��ƹ��캯����
class MyComplex_ref
{
	double real;
	double image;
public:
	MyComplex_ref(double r = 0.0, double i = 0.0)
	{
		real = r;
		image = i;
	}
	MyComplex_ref(const MyComplex_ref& src)
	{
		cout << "Copy Constructor" << endl;
		real = src.real;
		image = src.image;
	}
	void Show() const
	{
		cout << real << " + " << image << "i" << endl;
	}

	MyComplex_ref& operator = (const MyComplex_ref& src);
};


MyComplex_ref& MyComplex_ref::operator=(const MyComplex_ref& src)
{
	real = src.real;
	image = src.image;

	// ������������ʱ���󣬻���ø��ƹ��캯������ɽϴ���
	//return src;		// ��������д�������᷵�ض�����

	// ���ص�ǰ���������,��ʾ���õ�ǰ����
	return *this;
}


// Ϊ�˶�������ʵ����ʽ�������������һ�ɲ������µĺ���ԭ��
// istream& operator>>(istream&, className&);
// ostream& operator<<(ostream&, const className&);


int main()
{
	// ������2�θ��ƹ��캯������һ������c2 = c1��ʱ�򣬺����ķ���ֵ(��ʱ����)
	// ����c1����ģ��ڶ��η�����Ϊc3��ֵ��ʱ��c2���ø��ƹ��캯����������ʱ����
	MyComplex c1(2.3, 4.5), c2, c3;
	c1.Show();
	c3 = c2 = c1;
	c2.Show();
	c3.Show();

	// �������ò����ø��ƹ��캯��
	cout << endl;
	MyComplex_ref r1(2.3, 4.5), r2, r3;
	r1.Show();
	r3 = r2 = r1;
	r2.Show();
	r3.Show();

	system("pause");
	return 0;
}
