
#include <iostream>

using namespace std;

void test()
{
	char str[10] = "ABC����";
	wchar_t wstr[20] = L"ABC����";
	cout << "cout << str: " << str << endl;			// ok
	// ������cout�в�û�н�����Ӧ�Ĳ��������أ�����wchar_t���͵�
	// ����ֻ�Ǳ�����һ��ָ��������
	cout << "cout << wstr: " << wstr << endl;		// address
	wcout << "wcout << str: " << str << endl;		// ok
	// English Ok,Chinese error,than the wcout stream is wrong
	// Ĭ�������,ȫ��locale��"C"locale,wcout������������ַ��ĺ����ַ�
	// wcout << str;ʧ��,���º������������wcout����������ȫ����������
	// ״̬
	wcout << "wcout << wstr: " << wstr << endl;		
	cout << "******" << endl;						// ok
	wcout << "wcout << str: " << str << endl;		// non output
}

void test1()
{
	char str[10] = "ABC����";
	wchar_t wstr[20] = L"ABC����";
	cout << "cout << str: " << str << endl;			// ok
	cout << "cout << wstr: " << wstr << endl;		// address
	wcout << "wcout << str: " << str << endl;		// ok
	cout << "******" << endl;						// ok

	wcout.imbue(locale("CHS"));
	wcout << "wcout << wstr: " << wstr << endl;		
	// ��ʱchar*�����ͳɵ��ֽڱ�����ַ���
	wcout << "wcout << str: " << str << endl;		// ABC,no Chinese
}

int main()
{
	// test();
	test1();

	system("pause");
	return 0;
}