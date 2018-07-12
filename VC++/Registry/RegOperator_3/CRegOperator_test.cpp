
/***********************************************************************
 * �ļ���: CRegOperator_test.cpp
 * �ļ�����: �Է�װ��ע����������в���
 * ������: ����ʥ 20171104
 * �汾��: 1.0
 * �޸ļ�¼:
***********************************************************************/

#include "RegOperator.h"
#include <iostream>

void RegOperatorHelp(); 

using std::cout;
using std::endl;
using std::wcout;

int main(int argc, char* argv[])
{
	bool bReturn;
	// ������û�в��������������ʾ��Ϣ
	if(1 == argc)
	{
		RegOperatorHelp();
		//return 0;
	}

	//for (int i = 0; i < argc; ++i)
	//	assert(argv[i]);

	//TCHAR** wargv = new TCHAR*[argc - 1];
	//for (int i = 1; i < argc; ++i)
	//	wargv[i] = const_cast<TCHAR*>((CRegOperator::s2ws(argv[i])).c_str());

	TCHAR* wargv[4];
	wargv[0] = _T("-read");
	wargv[1] = _T("HKEY_CURRENT_USER");
	wargv[2] = _T("Software\\Wow6432Node\\Microsoft\\Windows\\CurrentVersion\\Uninstall\\{CF0F5650-A1B7-4ED0-88E1-91C37D1E9357}");
	wargv[3] = _T("Language");

	/*============================================================ 
    * ��֧���ܣ���ȡ��ֵ 
    * �Ρ�������-read  RootKey SubKey ValueName 
    * ����˵�������� ���� �Ӽ� ֵ������ 
    * �׳��쳣������ʧ�ܣ���ʾ��Ϣ 
    * �������ߣ�����ʥ 20171104
    *============================================================*/
	//if(0 == strcmp(argv[1], "-read"))
	//{
		//if(5 == argc)
		//{
			CRegOperator reg;
			DWORD dwRes;
			// ���õ�ǰ����
			bReturn = reg.SetHKEY(wargv[1]);

			if(false == bReturn)
			{
				// cout << "\nThe key [" << argv[2] << "] set fail!" << endl;
				cout << "failed" << endl;
				system("pause");
				return 0;
			}

			bReturn = reg.OpenKey(wargv[2]);
			if(false == bReturn)
			{
				//cout << "Open [" << argv[3] << "] fail!" << endl;
				cout << "failed" << endl;
				system("pause");
				return 0;
			}

			bReturn = reg.Read(wargv[3], &dwRes);
			if(false == bReturn)
			{
				// cout << "Read [" << argv[4] << "] fail!" << endl;
				cout << "failed" << endl;
				system("pause");
				return 0;
			}

			// cout << "The [" << argv[4] << "] value is [";
			wcout << "The [" << wargv[3] << "] value is [" << dwRes << "]" << endl;
			system("pause");
			return 0;
		//}
		//else
		//{
		//	cout << "Warning: Must have four param with /'-read/' option!" << endl;
		//	return 0;
		//}
	//}
}

void RegOperatorHelp()
{
	cout << " * �������ߣ�����ʥ, 2017��11��04��" << endl;  
    cout << "/*============================================================" << endl;  
    cout << "* ��֧���ܣ���ȡ��ֵ" << endl;  
    cout << "* �Ρ�������-read  RootKey SubKey ValueName" << endl;  
    cout << "* ����˵�������� ���� �Ӽ� ֵ������" << endl;  
    cout << "* �׳��쳣������ʧ�ܣ���ʾ��Ϣ��" << endl;  
    cout << "*============================================================*/" << endl;  
	cout << endl;  

	cout << "/*============================================================" << endl;  
    cout << "* ��֧���ܣ������Ӽ�" << endl;  
    cout << "* �Ρ�������-create  RootKey SubKey" << endl;  
    cout << "* ����˵�������� ���� �Ӽ�" << endl;  
    cout << "* �׳��쳣������ʧ�ܣ���ʾ��Ϣ��" << endl;  
    cout << "*============================================================*/" << endl;  
	cout << endl;  

    cout << "/*============================================================" << endl;  
    cout << "* ��֧���ܣ�������ֵ" << endl;  
    cout << "* �Ρ�������-write  RootKey SubKey ValueName Value" << endl;  
    cout << "* ����˵�������� ���� �Ӽ� ֵ������ ֵ" << endl;  
    cout << "* �׳��쳣������ʧ�ܣ���ʾ��Ϣ��" << endl;  
    cout << "*============================================================*/" << endl;  
	cout << endl;  

    cout << "/*============================================================" << endl;  
    cout << "* ��֧���ܣ�ɾ����ֵ" << endl;  
    cout << "* �Ρ�������-delval  RootKey SubKey ValueName" << endl;  
    cout << "* ����˵�������� ���� �Ӽ� ֵ������" << endl;  
    cout << "* �׳��쳣������ʧ�ܣ���ʾ��Ϣ��" << endl;  
    cout << "*============================================================*/" << endl;  
	cout << endl;  

    cout << "/*============================================================" << endl;  
    cout << "* ��֧���ܣ�ɾ���ǿ��Ӽ�" << endl;  
    cout << "* �Ρ�������-delkey  RootKey SubKey" << endl;  
    cout << "* ����˵�������� ���� �Ӽ�" << endl;  
    cout << "* �׳��쳣������ʧ�ܣ���ʾ��Ϣ��" << endl;  
    cout << "*============================================================*/" << endl;  
	cout << endl;  

    cout << "/*============================================================" << endl;  
    cout << "* ��֧���ܣ�����ע���" << endl;  
    cout << "* �Ρ�������-save  RootKey SubKey Filename" << endl;  
    cout << "* ����˵�������� ���� �Ӽ� �ļ���" << endl;  
    cout << "* �׳��쳣������ʧ�ܣ���ʾ��Ϣ��" << endl;  
    cout << "*============================================================*/" << endl;  
	cout << endl;  

    cout << "/*============================================================" << endl;  
    cout << "* ��֧���ܣ��ָ�ע���" << endl;  
    cout << "* �Ρ�������-restore  RootKey Filename" << endl;  
    cout << "* ����˵�������� ���� �ļ���" << endl;  
    cout << "* �׳��쳣������ʧ�ܣ���ʾ��Ϣ��" << endl;  
    cout << "*============================================================*/" << endl;  
	cout << endl;  

    cout << "/*============================================================" << endl;  
    cout << "* ��֧���ܣ�������Ϣ" << endl;  
    cout << "* �Ρ�������-h [-help]" << endl;  
    cout << "* ����˵��������" << endl;  
    cout << "* �׳��쳣������ʧ�ܣ���ʾ��Ϣ��" << endl;  
    cout << "*============================================================*/" << endl;  
	cout << endl;
}

