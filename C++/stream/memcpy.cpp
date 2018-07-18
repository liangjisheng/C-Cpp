#include"iostream"
#include"memory.h"
#include"assert.h"
using namespace std;

void* memcpy(char* memDest,char* memSrc,size_t size)
{
	assert((memDest!=NULL) && (memSrc!=NULL));
	char* pDest=memDest;
	char* pSrc=memSrc;
	while(size-->0)
		*pDest++=*pSrc++;
	*pDest='\0';
	return memDest;
}

int main(int argc,char* argv[])
{
	char str1[]="one tow three";
	char str2[81];
	// char ptr1[]="one two,three";
	memcpy(str2,str1,7);
	cout<<"source string:"<<str1<<endl;
	cout<<"Destiantion string:"<<str2<<endl;

	system("pause");
	return 0;
}