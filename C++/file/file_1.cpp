#include"stdio.h"
#include"windows.h"
#include"process.h"
#include"math.h"
#include"stdlib.h"
#include"string.h"

#include"ctype.h"
int main() 
{
	// ungetc:把字符退回到输入流
	int i=0;
	char ch;
	puts("Input an integer followed by a char:");
	// 读取字符知道输入非数字或EOF
	while((ch=getchar())!=EOF && isdigit(ch))
		i=10*i+ch-48; // 将ASCII 转换成整数值
	
	// 如果输入非数字，将其退回输入流
	if(ch!=EOF)
		ungetc(ch,stdin);
	printf("i=%d,next char in buffer=%c\n",i,getchar());
	
	return 0;
}