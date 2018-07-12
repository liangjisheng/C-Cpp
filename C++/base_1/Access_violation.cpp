// 不正确使用指针导致p1导致出现异常和正确使用数组实现字符串的连接

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc,char* argv[])
{
	char * p1 = (char *)malloc( sizeof(char)*20 );
	char p3[20]= "asdf";
	char * p2 = "qwer";
	p1 = "zxcv";        //p1指向"zxcv"的首地址, 而不是把"zxcv"拷贝到malloc开辟的内存块中
	//strcat( p1, p2 );   //报错: 0xC0000005异常，访问冲突
	strcat( p3, p2 );   //正确
	printf( "p1=[%s], p2=[%s]\n", p1, p2 );
	printf( "p3=[%s], p2=[%s]\n", p3, p2 );

	//释放内存
	// free( p1 );
	p1 = NULL;

	system("pause");
	return 0;
}