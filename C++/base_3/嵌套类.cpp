// 嵌套类的使用
#include"iostream"
#include"cstring"
using namespace std;
#define MAXLEN 128

class CList {
public:
	class CNode{
		friend class CList;
	private:
		int m_Tag;
	public:
		char m_Name[MAXLEN];
	};
	CNode node;
	void SetNodeName(const char * pName)
	{ strcpy(node.m_Name,pName); }
	void SetNodeTag(int tag)
	{ node.m_Tag=tag; }
	void Display()const 
	{ cout<<"Tag:"<<node.m_Tag<<","<<"Name:"<<node.m_Name<<endl; }
};

int main()
{
	CList m_list;
	m_list.SetNodeName("lishuyu");
	m_list.SetNodeTag(5);
	m_list.Display();

	system("pause");
	return 0;
}