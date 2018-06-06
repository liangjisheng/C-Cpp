
// tinyXML类库解析xml文件，将tinystr.h、tinystr.cpp、tinyxml.h、tinyxml.cpp、
// tinyxmlerror.cpp、tinyxmlparser.cpp，添加到自己的工程中去，最后只要#include "tinyxml.h"
// 就可以了

#include "tinyxml.h"
#include <iostream>

using std::cout;
using std::endl;

//像TiXmlDeclaration指的就是< ? xml version = "1.0" encoding = "UTF-8" ? >，
//像TiXmlComment指的就是<!--one item behalfs one contacted person.-->、 <!--more contacted persons.-->，
//像TiXmlDocument指的就是整个xml文档，
//像TiXmlElement指的就是<phonebook>、<item>、<name>、<addr>等等这些节点，
//像TiXmlText指的就是‘gougou’、‘15840330481’这些夹在<item>与< / item>、<name>与< / name>、<addr>与< / addr>之间的文本文字，
//像TiXmlAttribute指的就是< ? xml version = "1.0" encoding = "UTF-8" ? >节点中version、encoding，
//除此之外就是TiXmlUnknown。


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