#include"stdafx.h"
#include"iostream"
#include"string.h"
using namespace std;
#define MAX_LEN 128

struct Zone {
	int nID;	// ID
	char szName[MAX_LEN];// 区域名称
	int nHightID; // 上级区域ID
};

// ListZone() 实现节点的输出
void ListZone(Zone Nodes[],int nLen,int nID,int &nLevel)
{
	for(int i=0;i<nLen;i++) {
		if(Nodes[i].nHightID==nID) {
			for(int j=0;j<nLevel;j++)
				cout<<" ";	// 设置缩进
			cout<<Nodes[i].szName<<endl;
			nLevel++;		// 缩进的空格数
			ListZone(Nodes,nLen,Nodes[i].nID,nLevel);
			nLevel--;
		}
	}
}

int main(int argc,char * argv[])
{
	char * szName[10]={"吉林省","黑龙江省","长春市","松原市","辽源市",
		"四平市","扶余县","前郭县","宁江区","长岭县"};
	Zone Node[10];
	for(int i=0;i<10;i++) {
		Node[i].nID=i;
		strcpy(Node[i].szName,szName[i]);
		Node[i].nHightID=-1;		// 默认设置为-1，表示没有上级ID
	}
	// 设置上级ID
	Node[2].nHightID=0;
	Node[3].nHightID=0;
	Node[4].nHightID=0;
	Node[5].nHightID=0;
	Node[6].nHightID=3;
	Node[7].nHightID=3;
	Node[8].nHightID=3;
	Node[9].nHightID=3;

	int nLevel=2;
	for(int j=0;j<10;j++) {
		if(Node[j].nHightID==-1) {
			cout<<Node[j].szName<<endl;
			ListZone(Node,10,Node[j].nID,nLevel);
		}
	}
	return 0;
}