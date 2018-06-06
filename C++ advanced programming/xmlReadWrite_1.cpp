
#include <iostream>
#include <string>
#include <Windows.h>
#include <atlstr.h>		// for CString,_T()
#include "tinystr.h"
#include "tinyxml.h"

using namespace std;

// ��ȡӦ�ó����Ŀ¼
CString GetAppPath()
{
	TCHAR modulePath[MAX_PATH] = { 0 };
	GetModuleFileName(NULL, modulePath, MAX_PATH);
	CString strModulePath(modulePath);
	strModulePath = strModulePath.Left(strModulePath.ReverseFind(_T('\\')));
	return strModulePath;
}


bool CreateXmlFile(CString& szFileName)
{
	try {
		//����һ��XML���ĵ�����
		TiXmlDocument *myDocument = new TiXmlDocument();
		//����һ����Ԫ�ز����ӡ�
		TiXmlElement *RootElement = new TiXmlElement("Persons");
		myDocument->LinkEndChild(RootElement);
		//����һ��PersonԪ�ز����ӡ�
		TiXmlElement *PersonElement = new TiXmlElement("Person");
		RootElement->LinkEndChild(PersonElement);
		//����PersonԪ�ص����ԡ�
		PersonElement->SetAttribute("ID", "1");
		//����nameԪ�ء�ageԪ�ز����ӡ�
		TiXmlElement *NameElement = new TiXmlElement("name");
		TiXmlElement *AgeElement = new TiXmlElement("age");
		PersonElement->LinkEndChild(NameElement);
		PersonElement->LinkEndChild(AgeElement);
		//����nameԪ�غ�ageԪ�ص����ݲ����ӡ�
		TiXmlText *NameContent = new TiXmlText("������");
		TiXmlText *AgeContent = new TiXmlText("22");
		NameElement->LinkEndChild(NameContent);
		AgeElement->LinkEndChild(AgeContent);
		CString appPath = GetAppPath();
		CString seperator = "\\";
		CString fullPath = appPath.GetBuffer(0) + seperator + szFileName;
		myDocument->SaveFile(fullPath.GetBuffer(0));//���浽�ļ�
		fullPath.ReleaseBuffer();
	}
	catch (CString& e)
	{
		return false;
	}
	return true;
}


bool ReadXmlFile(CString& szFileName)
{
	try
	{
		CString appPath = GetAppPath();
		CString seperator = "\\";
		CString fullPath = appPath.GetBuffer(0) + seperator + szFileName;
		//����һ��XML���ĵ�����
		TiXmlDocument *myDocument = new TiXmlDocument(fullPath.GetBuffer(0));
		fullPath.ReleaseBuffer(0);
		myDocument->LoadFile();
		//��ø�Ԫ�أ���Persons��
		TiXmlElement *RootElement = myDocument->RootElement();
		//�����Ԫ�����ƣ������Persons��
		cout << RootElement->Value() << endl;
		//��õ�һ��Person�ڵ㡣
		TiXmlElement *FirstPerson = RootElement->FirstChildElement();
		//��õ�һ��Person��name�ڵ��age�ڵ��ID���ԡ�
		TiXmlElement *NameElement = FirstPerson->FirstChildElement();
		TiXmlElement *AgeElement = NameElement->NextSiblingElement();
		TiXmlAttribute *IDAttribute = FirstPerson->FirstAttribute();
		//�����һ��Person��name���ݣ��������ǣ�age���ݣ�����ID���ԣ�����
		cout << NameElement->FirstChild()->Value() << endl;
		cout << AgeElement->FirstChild()->Value() << endl;
		cout << IDAttribute->Value() << endl;
	}
	catch (CString& e)
	{
		return false;
	}
	return true;
}


int main()
{
	CString strFileName = "info.xml";
	CreateXmlFile(strFileName);
	ReadXmlFile(strFileName);

	system("pause");
	return 0;
}

