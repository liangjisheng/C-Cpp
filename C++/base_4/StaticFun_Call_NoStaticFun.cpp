
// C++静态成员函数调用非静态成员函数方法

#include <stdio.h>
#include <Windows.h>
#include <time.h>

class Class;

typedef struct
{
	Class *pClass;
	int x;
	int y;
}ParaNode;

class Class
{
public:
	int i;
	void Seti(int index) { i = index; }
	bool SaneCommandSASTest(int x, int y)
	{
		printf("sum: x + y = %d\n", x + y);
		srand((unsigned)time(NULL));
		int rate = rand() % 5;
		if (rate < 3)
			while (1);
		else if (3 == rate)
			return false;
		else
			return true;
	}

	static DWORD WINAPI SendEraseCommandThread(LPVOID lpParameter);
	int ExecuteCommand(int x, int y);
	int Print();
private:
	bool m_SendCommandResult;
	bool m_getProcessResult;
	int m_processResult;
};

DWORD WINAPI Class::SendEraseCommandThread(LPVOID lpParameter)
{
	ParaNode *paranode = (ParaNode *)lpParameter;
	printf("Enter into ThreadProc\n");
	paranode->pClass->m_SendCommandResult = false;
	paranode->pClass->m_SendCommandResult = paranode->pClass->SaneCommandSASTest(paranode->x, paranode->y);
	return 0;
}

int Class::Print()
{
	printf("----------- Print Test ------------\n");
	return 0;
}

int Class::ExecuteCommand(int x, int y)
{
	HANDLE hHandle;
	ParaNode node;
	node.pClass = this;
	node.x = x;
	node.y = y;
	hHandle = CreateThread(NULL, 0, &Class::SendEraseCommandThread, (LPVOID)&node, 0, NULL);

	if (WaitForSingleObject(hHandle, 1000) == WAIT_TIMEOUT)
		printf("ExecuteCommand SendEraseCommandThread TimeOut failed\n");
	else
	{
		if (m_SendCommandResult)
			printf("ExecuteCommand SendEraseCommandThread successfully\n");
		else
			printf("ExecuteCommand SendEraseCommandThread failed\n");
	}

	return 0;
}


int main()
{
	srand((unsigned)time(NULL));
	Class c1;
	c1.Seti(10);

	for (int i = 0; i < 1000; ++i)
		c1.ExecuteCommand(rand() % 500, rand() % 500);

	system("pause");
	return 0;
}