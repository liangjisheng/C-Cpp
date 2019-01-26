
// tinyXML������xml�ļ�����tinystr.h��tinystr.cpp��tinyxml.h��tinyxml.cpp��
// tinyxmlerror.cpp��tinyxmlparser.cpp����ӵ��Լ��Ĺ�����ȥ�����ֻҪ#include "tinyxml.h"
// �Ϳ�����

#include "tinyxml.h"
#include <iostream>

using std::cout;
using std::endl;

//��TiXmlDeclarationָ�ľ���< ? xml version = "1.0" encoding = "UTF-8" ? >��
//��TiXmlCommentָ�ľ���<!--one item behalfs one contacted person.-->�� <!--more contacted persons.-->��
//��TiXmlDocumentָ�ľ�������xml�ĵ���
//��TiXmlElementָ�ľ���<phonebook>��<item>��<name>��<addr>�ȵ���Щ�ڵ㣬
//��TiXmlTextָ�ľ��ǡ�gougou������15840330481����Щ����<item>��< / item>��<name>��< / name>��<addr>��< / addr>֮����ı����֣�
//��TiXmlAttributeָ�ľ���< ? xml version = "1.0" encoding = "UTF-8" ? >�ڵ���version��encoding��
//����֮�����TiXmlUnknown��


int main()
{
	const char* filePath = "phonebookdata.xml";
	TiXmlDocument doc(filePath);
	bool loadOkey = doc.LoadFile();

	/// failed to load phonebookdata.xml
	if (!loadOkey)
	{
		cout << "Counld not load test file " << filePath << endl;
		cout << "Error = " << doc.ErrorDesc() << endl;
		return -1;
	}

	// get dom root of phonebookdata.xml, here root should be 'phonebook'
	TiXmlElement* root = doc.RootElement();
	cout << "_____________________________________\n\n";
	cout << "    Contacted person information     \n\n";
	// trace every items below root.
	for (TiXmlNode* item = root->FirstChild("item");
		item;
		item = item->NextSibling("item"))
	{
		// read name
		TiXmlNode* child = item->FirstChild();
		const char* name = child->ToElement()->GetText();
		if (name)
			cout << "name: " << name << endl;
		else
			cout << "name: " << endl;

		// read address.
		child = item->IterateChildren(child);
		const char* addr = child->ToElement()->GetText();
		if (addr)
			cout << "addr: " << addr << endl;
		else
			cout << "addr: " << endl;

		// read telephone no.
		child = item->IterateChildren(child);
		const char* tel = child->ToElement()->GetText();
		if (tel)
			cout << "tel: " << tel << endl;
		else
			cout << "tel: " << endl;

		// read e-mail.
		child = item->IterateChildren(child);
		const char* email = child->ToElement()->GetText();
		if (email)
			cout << "email: " << email << endl;
		else
			cout << "email: " << endl;

		cout << endl;
	}



	// Add information to xml file and save it.
	TiXmlElement* writeRoot = doc.RootElement();
	TiXmlNode* newNode = new TiXmlElement("item");

	const TiXmlNode* name4NewNode = new TiXmlElement("name");
	newNode->InsertEndChild(*name4NewNode)->InsertEndChild(TiXmlText("pipi"));

	const TiXmlNode* addr4NewNode = new TiXmlElement("addr");
	newNode->InsertEndChild(*addr4NewNode)->InsertEndChild(TiXmlText("Shaanxi Xianyang"));

	const TiXmlNode* tel4NewNode = new TiXmlElement("tel");
	newNode->InsertEndChild(*tel4NewNode)->InsertEndChild(TiXmlText("02937310627"));

	const TiXmlNode* email4NewNode = new TiXmlElement("email");
	newNode->InsertEndChild(*email4NewNode)->InsertEndChild(TiXmlText("pipi@home.com"));

	writeRoot->InsertEndChild(*newNode);
	doc.SaveFile();

	system("pause");
	return 0;
}