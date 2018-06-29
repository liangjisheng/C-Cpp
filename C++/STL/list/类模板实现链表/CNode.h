#include"iostream"
#include"iomanip"
using namespace std;

template<class Type>  //定义类模板
class CList{
private:
	Type *m_pHeader; //头节点
	int m_NodeSum;  //节点数量
public:
	CList(){m_pHeader=NULL;m_NodeSum=0;}
	Type *MoveTrail()
	{
		Type *pTmp=m_pHeader;
		for(int i=1;i<m_NodeSum;i++)
			pTmp=pTmp->m_pNext;
		return pTmp;
	}
	void AddNode(Type *pNode)
	{
		if(m_NodeSum==0)m_pHeader=pNode;
		else {Type *pTrail=MoveTrail();pTrail->m_pNext=pNode;}
		m_NodeSum++;
	}
	void PassList()
	{
		if(m_NodeSum>0){
			Type *pTmp=m_pHeader;
			cout<<setw(4)<<dec<<pTmp->m_Data;
			for(int i=1;i<m_NodeSum;i++)
			{pTmp=pTmp->m_pNext;cout<<setw(4)<<pTmp->m_Data;}
		}
	}
	~CList()
	{
		if(m_NodeSum>0){
			Type *pDelete=m_pHeader;
			Type *pTmp=NULL;
			for(int i=0;i<m_NodeSum;i++){
				pTmp=pDelete->m_pNext;
				delete pDelete;
				pDelete=pTmp;
			}
			m_NodeSum=0;
			pDelete=NULL;
			pTmp=NULL;
		}
		m_pHeader=NULL;
	}
};

class CNode{
public:
	CNode *m_pNext;
	int m_Data;
	CNode(){m_pNext=NULL;}
};
class CNet{
public:
	CNet *m_pNext;
	char m_Data;
	CNet(){m_pNext=NULL;}
};