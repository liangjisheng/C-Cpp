
// ������һ��ö������֮���൱���ṩ�����ɴ��������ķ��ų���
#include <iostream>

using std::cout;
using std::endl;

enum weekDay{ Sun, Mon, Tue, Wed, Thu, Fri, Sat };

// ��һ���������ڿ��Զ�����ö�����ͣ���������ö�ٳ�����Ӧ��ͬ������ֵ��
// ���������κ�����ö�ٳ���ͬ�����������ֱ����������һ�еĴ�������
// ������������������ʹ��ö�ٳ�������������Ҫ����ö�ٱ��������ڶ���
// ö������ʱö��������Ҳ����ʡ��
// enum weekDay1{ Sun, Mon, Tue, Wed, Thu, Fri, Sat };


void test()
{
	weekDay day;
	cout << Sun << " " << Mon << " " << Tue << " " << Wed << " "
		<< Thu << " " << Fri << " " << Sat << endl;

	// ֻ�ܽ�ö�ٳ�����������������ֱ�ӽ�����ֵ�������������ʱ��
	// ֱ���������ֵ����Ӧ������ֵ
	day = Sat;
	cout << day << endl;
	cout << sizeof(weekDay) << endl;
	cout << sizeof(day) << endl;
}


// ö�ٳ������������������еľ�̬���ͳ���������Ҫע������ֻ�Ƿ��ų�����
// �ǲ���Ѱַ�ģ��ڱ���׶ξ��Ѿ��滻Ϊ��Ӧ������ֵ

class someclass
{
public:
	static const int coint = 4;
	enum weekDay{ Mon = 2, Tue, Wed, Thu = 100, Fri, Sat, Sun };
	// ��int[7]�����ض���Ϊintarray
	typedef int intarray[7];
	someclass() { memset(this, 0, sizeof(someclass)); }

	intarray ia;
};


void test_1()
{
	someclass sc;
	cout << someclass::coint << endl;
	cout << someclass::Mon << " " << someclass::Tue << " "
		<< someclass::Wed << " " << someclass::Thu << " "
		<< someclass::Fri << " " << someclass::Sat << " "
		<< someclass::Sun << endl;

	for(int i = 0; i < 7; i++)
		cout << sc.ia[i] << " ";
	cout << endl;
	cout << endl;

	someclass::intarray ia;
	ia[0] = someclass::Mon;
	ia[1] = someclass::Tue;
	ia[2] = someclass::Wed;
	ia[3] = someclass::Thu;
	ia[4] = someclass::Fri;
	ia[5] = someclass::Sat;
	ia[6] = someclass::Sun;
	
	for(int i = 0; i < 7; i++)
		cout << ia[i] << " ";
	cout << endl;

	cout << someclass::coint << endl;
}


int main()
{
	// test();
	test_1();

	system("pause");
	return 0;
}