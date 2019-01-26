#include"iostream"
#include"CNode.h"
using namespace std;
int main(int argc,char *argv[])
{
	CList<CNode>nodelist;  //构造一个类模板实例
	for(int n=0;n<5;n++){
		CNode *pNode=new CNode();
		pNode->m_Data=n;
		nodelist.AddNode(pNode);
	}
	nodelist.PassList();
	cout<<endl;
	CList<CNet>netlist;
	for(int i=0;i<5;i++){
		CNet *pNode=new CNet();
		pNode->m_Data=97+i;
		netlist.AddNode(pNode);
	}
	netlist.PassList();
	cout<<endl;
	return 0;
}