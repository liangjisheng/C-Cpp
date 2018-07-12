
#ifdef _DEBUG

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#define new new(_NORMAL_BLOCK, __FILE__, __LINE__)

#endif


#include <iostream>
#include <Windows.h>

using std::cout;
using std::endl;

char new_index_recorder_file_name[1024 * 1024][256]; 

class new_index_recorder
{
public:
	new_index_recorder(char* file, int line) : file(file), line(line) {}
	operator char* ()
	{
		static unsigned int index;
		sprintf(new_index_recorder_file_name[index], "%s(%d) : %d ", file, line, index++);
		return new_index_recorder_file_name[index];
	}

private:
	char *file;
	int line;
};


int g_count = 0;

class OperNew 
{
public:
	OperNew()
	{
		g_count++;
		pc = new char[20];
		memset(pc, 0, 20);
		sprintf(pc, "No.%d", g_count);
	}

	~OperNew() 
	{
		if (pc)
		{
			delete [] pc;
			pc = NULL;
		}
	}

	char* getChar() { return pc; }
private:
	char *pc;
};


int main()
{
	_CrtSetDbgFlag(_CrtSetDbgFlag(_CRTDBG_REPORT_FLAG) | _CRTDBG_LEAK_CHECK_DF);

	int num = 10;
	BYTE **p = new BYTE*[10];
	for (int i = 0; i < num; ++i)
		p[i] = new BYTE[i];

	for (int i = 0; i < num; ++i)
	{
		delete [] p[i];
		p[i] = NULL;
	}
	delete [] p;
	p = NULL;

	long *pl = new long[100];
	delete [] pl;
	pl = NULL;

	OperNew testnew;


	system("pause");
	return 0;
}