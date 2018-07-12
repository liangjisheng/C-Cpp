#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int main()
{
	//待去掉前后空格的字符串(共10字节),如果用常量存储，会发生访问冲突
	// char * pcontent = "  abcdef  "; 
	char ccontent[20] = "  abcdef  ";
	char * p = NULL;
	printf("Line=[%d],ccontent=[%s]\n",__LINE__,ccontent);

	// 去除后面的空格
	p = ccontent + strlen( ccontent ) - 1;  //指针p指向字符串的末尾
	while( *p == 0x20 )
		p--;
	// 因为pcontent是常量，常量在内存中是不能被修改的，所以会发生访问冲突
	// 要用数组来存储字符串，存储在栈里，而不是才存储在全局静态区
	// 另外，对于内存中的 0x00000000 地址，不能执行读取和写入操作。
	// 例如前面的char * p = NULL;这种指针初始化（避免成为野指针）操作，
	// 在后面不能直接来一个printf("%c", *p)，否则就会出现错
	*(p+1) = 0x00;  //将字符串中‘f’后面的一位空格改成结束符号'\0'
	printf( "Line=[%d], ccontent=[%s]\n", __LINE__, ccontent );

	// 去除前面的空格
	p = ccontent;
	while(*p == 0x20)
		p++;
	// ccontent = p;
	printf("Line=[%d],ccontent=[%s]\n",__LINE__,p);

	system("pause");
	return 0;
}