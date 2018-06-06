
#include <iostream>
#include <locale>
#include <fstream>

using std::cout;
using std::endl;
using std::wcout;
using std::locale;
using std::ofstream;
using std::wofstream;

// �����ַ���
void test_1()
{
	// Ĭ��Clocale����£�cout����ֱ��������ģ���wcoutȷ���У�
	// ��Ҫ����locale��Ϊ��������
	cout << "test" << endl;
	cout << "����" << endl;
	cout << L"test" << endl;
	cout << L"����" << endl;
	cout << endl;

	wcout << "test" << endl;
	wcout << "����" << endl;
	wcout << L"test" << endl;
	// ��locale��Ϊ����, Ҳ����ʹ��wcout.imbue(locale(""));
	// ��������ı�wcout������locale���ã���������1234����1,234
	// ���������仰ֻ�ı���ַ��������
	wcout.imbue(locale(locale(), "", LC_CTYPE));
	wcout << L"����" << endl;		// û�н�locale��Ϊ���صĻ��Ͳ������
	cout << endl;

	wcout << "test" << endl;
	// ��locale��Ϊ���غ��������д���Ĳ������
	wcout << "����" << endl;
	wcout << L"test" << endl;
	wcout << L"����" << endl;
}

// ���������ļ�������������
void test_2()
{
	ofstream ofs("test_1_1.txt");
	ofs << "this is a test line" << endl;
	ofs.close();

	ofs.open("����_0_1.txt");
	ofs << "this is a test line" << endl;
	ofs.close();

	ofs.open("test_1_0.txt");
	ofs << "����һ��������" << endl;
	ofs.close();

	ofs.open("����_0_0.txt");
	ofs << "����һ��������" << endl;
	ofs.close();

	//ofstream ofs(L"test_1_1.txt");			// error
	//ofs << L"this is a test line" << endl;	// error
	//ofs.close();

	//ofs.open(L"����_0_1.txt");
	//ofs << L"this is a test line" << endl;
	//ofs.close();

	//ofs.open(L"test_1_0.txt");
	//ofs << L"����һ��������" << endl;
	//ofs.close();

	//ofs.open(L"����_0_0.txt");
	//ofs << L"����һ��������" << endl;
	//ofs.close();

	// ���Ҫ������ĵĻ�����Ҫ��ȫ��locale��Ϊ��������,Ĭ�������
	// wofstream�ǲ���������ĵ�
	locale &loc = locale::global(locale(locale(), "", LC_CTYPE));
	wofstream wofs(L"w_test_1_1.txt");
	wofs << L"this is a test line" << endl;
	wofs.close();

	wofs.open(L"w_����_0_1.txt");
	wofs << L"this is a test line" << endl;
	wofs.close();

	wofs.open(L"w_test_1_0.txt");
	wofs << L"����һ��������" << endl;
	wofs.close();

	wofs.open(L"w_����_0_0.txt");
	wofs << L"����һ��������" << endl;
	wofs.close();

	// �ָ�ԭ��������,wcout����������ģ������֮��
	locale::global(loc);

	wcout << L"test" << endl;
	wcout << L"����" << endl;
}

int main()
{
	// test_1();
	test_2();

	system("pause");
	return 0;
}