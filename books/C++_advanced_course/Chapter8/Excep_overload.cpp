
// !��һ��һԪ������,ͨ�����ڱ�ʾbool,��ʾ���߼�ȡ��������ĳ�����ж�!
// ��������������ʱ��ͨ����������Ķ���������쳣״����������ԶԲ���
// ���������أ��Ա���new���ɵĶ����Ƿ���ɹ�

#include <iostream>

using namespace std;

class A
{
	int m;
	char *str1;
	char *str2;
public:
	A(int n1, int n2, int n3)
	{
		str1 = new char[n1];
		str2 = new char[n2];
		m = n3;
	}

	~A()
	{
		delete []str1;
		str1 = NULL;
		delete []str2;
		str2 = NULL;
	}

	void show() { cout << m << endl; }
};

class A1
{
	int m;
	char *str1;
	char *str2;
public:
	A1(int n1, int n2, int n3)
	{
		str1 = new char[n1];
		str2 = new char[n2];
		m = n3;
	}

	~A1()
	{
		delete []str1;
		str1 = NULL;
		delete []str2;
		str2 = NULL;
	}

	void show() { cout << m << endl; }

	bool ObjOk()
	{
		if(str1 && str2) return true;
		else return false;
	}
};

// ͨ����operator!�������������أ������ж�һ����A2��������ݳ�Ա�Ƿ��������
// (�ռ��Ƿ�ɹ�����).������ͨ��ָ�롢�ļ�ָ�롢���󶼿���ͳһ����operator!
// ���ж��Ƿ�����쳣
class A2
{
	int m;
	char *str1;
	char *str2;
public:
	A2(int n1, int n2, int n3)
	{
		str1 = new char[n1];
		str2 = new char[n2];
		m = n3;
	}

	~A2()
	{
		delete []str1;
		str1 = NULL;
		delete []str2;
		str2 = NULL;
	}

	void show() { cout << m << endl; }

	// ����operator!��ʾ����Ľ����Ƿ����쳣
	bool operator!()
	{
		if(str1 && str2) return false;
		return true;
	}
	// ������Ϊ���Ա������Ҳ������Ϊ��Ԫ����
	// friend bool operator!(const A2 &a);
};

//bool operator!(const A2 &a)
//{
//	if(a.str1 && a.str2) return false;
//	else return true;
//}


int main()
{
	// �ڴ���������,��A�ķ������������������,������д�����4�г�����
	// ����ȱ�ݵ�,��Ϊ��new�����ڶ�������ռ�,�п��ܻ�ʧ��.���,��Ϊ�Ƚ�
	// �������Ƕ����е�new����������в��ԣ���ȷ�����󱻳ɹ��Ĵ���,�޸ĺ�
	// ����Ϊ��A1
	A *p = new A(4, 5, 6);
	p->show();
	delete p;
	p = NULL;

	// ��ObjOk()�����ĳ�����ô���Ũ��ĳ���Ա�ĸ��˷��,ͨ�����ظ����
	// operator!���������Ϳ��Խ�����ļ�⹤��ͳһ��ʾ:��A2
	A1 *p1 = new A1(4, 5, 6);
	if(p1 && p1->ObjOk())
		p1->show();
	delete p1;
	p1 = NULL;

	A2 *p2 = new A2(4, 5, 6);
	if(!p2 || !(*p2))
		cout << "new operator failed" << endl;
	else
		p2->show();
	delete p2;
	p2 = NULL;

	system("pause");
	return 0;
}