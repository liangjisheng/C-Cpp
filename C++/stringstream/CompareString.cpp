
#include <Windows.h>
#include <tchar.h>
#include <iostream>

using std::cout;
using std::endl;

// �˺��������Ƚ����ַ���
//int CompareString(  
	//LCID Locale,       // locale identifier  
	//DWORD dwCmpFlags,  // comparison-style options  
	//LPCTSTR lpString1, // first string  
	//int cchCount1,     // size of first string  
	//LPCTSTR lpString2, // second string  
	//int cchCount2      // size of second string  
	//);  

// ����CompareString�ķ���ֵ������C�����ڿ��*cmp�ַ����Ƚ�
// ���������ص�ֵ��CompareString����0ָʾʧ�ܣ�CSTR_LESS_THAN
// (����Ϊ1)ָʾpString1С��pString2��CSTR_EQUAL������Ϊ2��
// ָʾpString1��pString2��ȣ�CSTR_GREATER_THAN������Ϊ3��
// ָʾpString1����pString2��Ϊ����΢����Щ����������ɹ���
// �����÷���ֵ��ȥ2����ʹ�����C�����ڿ⺯���ķ���ֵһ�£�-1��0��+1����


void Compare()
{
	TCHAR szBuffer[10] = { 
		TEXT('A'), TEXT('A'), TEXT('A'), TEXT('A'), TEXT('A'),
		TEXT('A'), TEXT('A'), TEXT('A'), TEXT('A'), '\0' 
	};

	// �õ������̵߳�id,���ǵ�������̵߳ĵط�id��//$0804�����ģ�$0409��Ӣ�� - ������
	// $042A��Խ�ϣ�
	// SetThreadLocale�޸ĵ���control panel �е��������üȵ�һ��ѡ��е����ã�
	// ���ǵ�����ѡ�������(��һ��ѡ�������Ӱ��������ڸ�ʽ����������ѡ�
	// ������Ӱ��Ĳ�����Ӣ�Ļ���)��SetThreadLocale�����ܸ���ϵͳ�����Ի�����
	// ���õ���ѡ��������Ӧ��SetLocaleInfo ������
	// LCID���Ե����������û��߷���һ������ָ�����ػ���ĳ���������ʵ�����
	// ����ĳ��������������ڡ�ʱ���Լ�����
	LCID local = GetThreadLocale();
	int result = CompareString(local, NORM_IGNORECASE, 
		szBuffer, _countof(szBuffer), 
		TEXT("AAAAAAAAA"), 10);

	switch(result)
	{
	case 0:
		cout << "error" << endl;
		break;
	case CSTR_LESS_THAN:
		cout << "str1 > str2" << endl;
		break;
	case CSTR_GREATER_THAN:
		cout <<  "str1 < str2" << endl;
		break;
	case CSTR_EQUAL:
		cout << "str1 == str2" << endl;
		break;
	default:
		cout << "Don't goto there" << endl;
		break;
	}

	cout << result << endl;
}


int main()
{
	Compare();

	system("pause");
	return 0;
}