
#include <iostream>
#include <string>
#include <Windows.h>
#include <atlstr.h>		// for CString,_T()
#include "tinystr.h"
#include "tinyxml.h"

using namespace std;

// 获取应用程序根目录
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
		//创建一个XML的文档对象。
		TiXmlDocument *myDocument = new TiXmlDocument();
		//创建一个根元素并连接。
		TiXmlElement *RootElement = new TiXmlElement("Persons");
		myDocument->LinkEndChild(RootElement);
		//创建一个Person元素并连接。
		TiXmlElement *PersonElement = new TiXmlElement("Person");
		RootElement->LinkEndChild(PersonElement);
		//设置Person元素的属性。
		PersonElement->SetAttribute("ID", "1");
		//创建name元素、age元素并连接。
		TiXmlElement *NameElement = new TiXmlElement("name");
		TiXmlElement *AgeElement = new TiXmlElement("age");
		PersonElement->LinkEndChild(NameElement);
		PersonElement->LinkEndChild(AgeElement);
		//设置name元素和age元素的内容并连接。
		TiXmlText *NameContent = new TiXmlText("周星星");
		TiXmlText *AgeContent = new TiXmlText("22");
		NameElement->LinkEndChild(NameContent);
		AgeElement->LinkEndChild(AgeContent);
		CString appPath = GetAppPath();
		CString seperator = "\\";
		CString fullPath = appPath.GetBuffer(0) + seperator + szFileName;
		myDocument->SaveFile(fullPath.GetBuffer(0));//保存到文件
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
		//创建一个XML的文档对象。
		TiXmlDocument *myDocument = new TiXmlDocument(fullPath.GetBuffer(0));
		fullPath.ReleaseBuffer(0);
		myDocument->LoadFile();
		//获得根元素，即Persons。
		TiXmlElement *RootElement = myDocument->RootElement();
		//输出根元素名称，即输出Persons。
		cout << RootElement->Value() << endl;
		//获得第一个Person节点。
		TiXmlElement *FirstPerson = RootElement->FirstChildElement();
		//获得第一个Person的name节点和age节点和ID属性。
		TiXmlElement *NameElement = FirstPerson->FirstChildElement();
		TiXmlElement *AgeElement = NameElement->NextSiblingElement();
		TiXmlAttribute *IDAttribute = FirstPerson->FirstAttribute();
		//输出第一个Person的name内容，即周星星；age内容，即；ID属性，即。
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

