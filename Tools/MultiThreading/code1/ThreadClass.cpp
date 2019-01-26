
#include <stdio.h>
#include <windows.h>

struct AAA
{
	int a;
	int b;
};

class AThread
{
private:
	DWORD id;
	AAA a;
public:
	void run()
	{
		HANDLE hand = CreateThread(0,0,ThreadFunc,&a,0,&id);
		// 等线程运行完之后在继续往下走，INFINITE表示一直等待，直到线程运行完
		WaitForSingleObject(hand,INFINITE);
	}
	static DWORD WINAPI ThreadFunc(LPVOID p)
	{
		AAA *a = (AAA*)p;
		a->a = 1;
		a->b = 2;
		printf("AAA::a = %d\n",a->a);
		printf("AAA::b = %d\n",a->b);

		for(int i=0;i<1000;i++)
			printf("asdf");
		printf("\n");

		ExitThread((DWORD)a);
		return 0;
	}
};

int main(int argc,char* argv[])
{
	AThread at;
	printf("创建线程......\n");
	printf("等待线程执行完毕......\n");
	at.run();
	printf("线程执行完毕\n");

	getchar();
	return 0;
}