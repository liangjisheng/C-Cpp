// Using rvalue
#include <iostream>
#include <cstring>
#include <utility>
using std::cout;
using std::endl;

class CText
{
private:
	char* pText;
public:
	CText(const char* pStr = "Default text");
	CText(const CText& txt);
	CText(CText&& txt);
	~CText();
	CText& operator=(const CText& txt);
	CText& operator=(CText&& txt);
	CText operator+(const CText& txt) const;
	void Show() const;
};

CText::CText(const char* pStr)
{
	cout << "\nCText constructor called.\n";
	size_t len(strlen(pStr) + 1);
	pText = new char[len];
	strcpy_s(pText, len, pStr);
}

CText::CText(const CText& txt)
{
	cout << "\nCText Copy constructor called.\n";
	size_t len = strlen(txt.pText) + 1;
	pText = new char[len];
	strcpy_s(pText, len, txt.pText);
}

// Move constructor definition
CText::CText(CText&& txt)
{
	cout << "\nCText move constructor called.\n";
	pText = txt.pText;
	txt.pText = nullptr;
}

CText::~CText()
{
	cout << "\nCText Destructor called.\n";
	delete[]pText;
}

CText& CText::operator=(const CText& txt)
{
	cout << "\nCText assgiment operator fucntion called.\n";
	if (this == &txt)
		return *this;

	delete[]pText;
	size_t len(strlen(txt.pText) + 1);
	pText = new char[len];
	strcpy_s(pText, len, txt.pText);
	return *this;
}

CText& CText::operator=(CText&& txt)
{
	cout << "\nCText move assignment operator function called.\n";
	delete[]pText;
	pText = txt.pText;
	txt.pText = nullptr;
	return *this;
}

CText CText::operator+(const CText& txt) const
{
	cout << "\nCText add operator function called.\n";
	CText tmp;
	size_t len = strlen(txt.pText) + strlen(pText) + 1;
	tmp.pText = new char[len];
	strcpy_s(tmp.pText, len, pText);
	strcat_s(tmp.pText, len, txt.pText);
	return tmp;
}

void CText::Show() const
{
	cout << pText << endl;
}

class CMessage
{
private:
	CText text;
public:
	CMessage(const char* str="Default message");
	CMessage(const CMessage& aMsg);
	CMessage(CMessage&& aMsg);
	~CMessage();
	CMessage& operator=(const CMessage& aMsg);
	CMessage& operator=(CMessage&& aMsg);
	void Show() const;
	CMessage operator+(const CMessage& aMsg) const;
};

CMessage::CMessage(const char* str)
{
	cout << "\nCMessage constructor called.\n";
	text = CText(str);
}

CMessage::CMessage(const CMessage& aMsg)
{
	cout << "\nCMessage copy constructor called.\n";
	text = aMsg.text;
}

CMessage::CMessage(CMessage&& aMsg)
{
	cout << "\nCMessage move constructor called.\n";
	text = std::move(aMsg.text);
}

CMessage::~CMessage()
{
	cout << "\nCMessage destructor called.\n";
}

CMessage& CMessage::operator=(const CMessage& aMsg)
{
	cout << "\nCMessage copy assignment operator function called.\n";
	if (this == &aMsg)
		return *this;
	text = aMsg.text;
	return *this;
}

CMessage& CMessage::operator=(CMessage&& aMsg)
{
	cout << "\nCMessage move assignment operator function called.\n";
	text = aMsg.text;
	return *this;
}

void CMessage::Show() const
{
	text.Show();
}

CMessage CMessage::operator+(const CMessage& aMsg) const
{
	cout << "\n CMessage add operator function called.\n";
	CMessage tmp;
	tmp.text = text + aMsg.text;
	return tmp;
}

int main(void)
{
	CMessage motto1("li");
	cout<<"Done\n\n";
	CMessage motto2("shu");
	cout<<"Done\n\n";
	motto1.Show();
	motto2.Show();

	cout << "\nExecuting: CMessage motto3(motto1+motto2).\n";
	CMessage motto3(motto1 + motto2);
	cout << "Done.\n\n" << "motto3 contains - ";
	motto3.Show();

	CMessage motto4;
	cout << "\nExecuting: motto4=motto3+motto2.\n";
	motto4 = motto3 + motto2;
	cout << "Done.\n\n" << "motto4 contains - ";
	motto4.Show();

	system("pause");
	return 0;
}