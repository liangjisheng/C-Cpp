// Using of Destructor
#include <iostream>
#include <cstring>
using std::cout;
using std::endl;

class CMessage
{
private:
	char* m_pMessage;
public:
	CMessage(const char* text = "Default message");
	~CMessage();
	CMessage(const CMessage& aMsg);
	CMessage(CMessage&& aMsg);
	CMessage& operator=(const CMessage& aMsg);
	CMessage& operator=(CMessage&& aMsg);
	void Show() const;
	void Reset();
	CMessage operator+(const CMessage& aMsg) const;
};

CMessage::CMessage(const char* text)
{
	cout << "\nDefault constructor called.\n";
	m_pMessage = new char[strlen(text) + 1];
	strcpy_s(m_pMessage, strlen(text)+1, text);
}

CMessage::~CMessage()
{
	cout << "\nDestructor called.\n";
	if(m_pMessage)
		delete[]m_pMessage;
}

CMessage::CMessage(const CMessage& aMsg)
{
	cout << "\nCopy constructor called.\n";
	size_t len = strlen(aMsg.m_pMessage) + 1;
	m_pMessage = new char[len];
	strcpy_s(m_pMessage, len, aMsg.m_pMessage);
}

// ������ĸ��ƹ��캯����ֻ�ƶ�ָ�룬Ч�ʸ�
CMessage::CMessage(CMessage&& aMsg)
{
	cout << "\nMove copy constructor called.\n";
	m_pMessage = aMsg.m_pMessage;
	aMsg.m_pMessage = nullptr;
}

// ��������������Ϊ����ʽ���ʽ
CMessage& CMessage::operator=(const CMessage& aMsg)
{
	cout << "\nAssignment operator funciton called.\n";
	if (this == &aMsg)
		return *this;
	delete[]m_pMessage;
	size_t len = strlen(aMsg.m_pMessage)+1;
	m_pMessage = new char[len];
	strcpy_s(m_pMessage, len, aMsg.m_pMessage);
}

// ������ֵ�������صĸ�ֵ���������Ҳ�������һ��rvalue,
// ����ʱ���󣬵��ô˺��������Ҳ�������һ��lvalue,
// ����ԭʼ������ֻ�ı�ԭʼ�����ָ�룬Ч�ʸ���
CMessage& CMessage::operator=(CMessage&& aMsg)
{
	cout << "\nMove assignment operator function called.\n";
	delete[] m_pMessage;
	m_pMessage = aMsg.m_pMessage;
	aMsg.m_pMessage = nullptr;
	return *this;
}

void CMessage::Show() const
{
	cout << m_pMessage << endl;
}

void CMessage::Reset()
{
	char* tmp = m_pMessage;
	while (*tmp)
		*(tmp++) = '*';
}

CMessage CMessage::operator+(const CMessage& aMsg) const
{
	cout << "\nAdd operator function called.\n";
	CMessage tmp;
	size_t len = strlen(m_pMessage) + strlen(aMsg.m_pMessage) + 1;
	tmp.m_pMessage = new char[len];
	strcpy_s(tmp.m_pMessage, len, m_pMessage);
	strcat_s(tmp.m_pMessage, len, aMsg.m_pMessage);
	return tmp;
}

int main(void)
{
	CMessage msg("lishuyu");
	msg.Show();
	CMessage* pMsg(new CMessage("lishuyu"));
	pMsg->Show();

	CMessage msg_1;
	msg_1= msg + *pMsg;
	cout << "\nDone\n";
	msg_1.Show();

	delete pMsg;
	pMsg = nullptr;

	CMessage motto1("The devil takes care of his own");
	CMessage motto2;

	cout << "motto2 contains - ";
	motto2.Show();

	motto2 = motto1;

	cout << "motto2 contains - ";
	motto2.Show();

	motto1.Reset();

	cout << "motto1 now contains - ";
	motto1.Show();

	cout << "motto2 now contains - ";
	motto2.Show();

	system("pause");
	return 0;
}