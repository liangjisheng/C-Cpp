#include"iostream"
#include"tchar.h"
using namespace std;
#define ACTION_SIZE 5

template<class T>
class actioncontainer {
private:
	int m_nRedoPos;		// 记录动作的位置
	int m_nUndoPos;
	// 使用常量表示可以撤销的动作，也就是容器的容量
	// const int ACTION_SIZE;
	T m_RedoAction[ACTION_SIZE];
	T m_UndoAction[ACTION_SIZE];
public:
	actioncontainer()
	{ m_nRedoPos=0; m_nUndoPos=0; }
	void add(T value);	// 向容器中添加新的动作
	T Redo();
	T Undo();
};

template<class T>
void actioncontainer<T>::add(T value) {
	if(m_nUndoPos>=ACTION_SIZE) {
		m_nUndoPos=ACTION_SIZE-1;
		for(int i=0;i<ACTION_SIZE;i++)
			m_UndoAction[i]=m_UndoAction[i+1];
	}
	m_UndoAction[m_nUndoPos++]=value;
}

template<class T>
T actioncontainer<T>::Undo() {
	// 将撤销的动作复制到恢复数组中
	m_RedoAction[m_nRedoPos++]=m_UndoAction[--m_nUndoPos];
	// 返回撤销的动作
	return m_UndoAction[m_nUndoPos];
}

template<class T>
T actioncontainer<T>::Redo() {
	// 将恢复的动作复制到撤销数组中
	m_UndoAction[m_nUndoPos++]=m_RedoAction[--m_nRedoPos];
	// 返回恢复的动作
	return m_RedoAction[m_nRedoPos];
}

int _tmain(int argc,_TCHAR* argv[])
{
	actioncontainer<int> intaction;
	intaction.add(1);
	intaction.add(2);
	intaction.add(3);
	intaction.add(4);
	// 撤销上一步动作
	int nUndo=intaction.Undo();
	cout<<nUndo<<endl;
	nUndo=intaction.Undo();
	cout<<nUndo<<endl;
	int nRedo=intaction.Redo();
	cout<<nRedo<<endl;
	nRedo=intaction.Redo();
	cout<<nRedo<<endl;

	system("pause");
	return 0;
}