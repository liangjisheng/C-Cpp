// 列举出所有hart的组合
// h a r t ha hr ht ar at rt har hat hrt art hart
// Algorithm
// 1、从首字符到尾字符的各个字符，循环
// 2、输出被循环到的字符1
// 3、如果循环到字符1后面还有字符，递归，以后面的字符为起始字符，重复2,3
// 4、如果被循环到的字符1后面没有字符，跳出循环
#include"iostream"
using namespace std;
int sum=0;
char str[]="hart";
int length;
char * out;

void DoCombine(char in[],char out[],int length,int rec,int start) 
{
	int i;
	for(i=start;i<length;i++) {
		out[rec]=in[i];
		out[rec+1]=0;
		printf("%s\n",out);
		sum++;
		if(i<length-1)
			DoCombine(in,out,length,rec+1,i+1);
	}
}

int main()
{
	length=strlen(str);
	out=new char[length+1];
	DoCombine(str,out,length,0,0);
	printf("总共有%d种组合\n",sum);

	system("pause");
	return 0;
}