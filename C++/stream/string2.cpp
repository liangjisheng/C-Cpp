#include"stdio.h"
#include"stdlib.h"
#include"string.h"

/*int main() {
	// atof:字符串转浮点型函数
	char *str="12345.67";
	float result;
	result=atof(str);
	printf("string=%s\nfloat=%f\n",str,result);
	getchar();
	return 0;
}*/

/*int main() {
	// atoi:字符串转整型
	char *str="12345.67";
	int result;
	result=atoi(str);
	printf("string=%s\ninteger=%d\n",str,result);
	getchar();
	return 0;
}*/
// atol:字符串转长整型

/*int main() {
	// memchr:字符搜索函数,在str前strlen(str)个字符中搜索C第一次出现的位置
	char *str="I love China\n";
	char *p;
	p=(char*)memchr(str,'C',strlen(str));
	if(p) printf("%s\n",p);
	else printf("The character was not found\n");
	return 0;
}*/

/*int main() {
	// memcmp:字符串比较
	char *str1="ABCDEF";
	char *str2="ABCDEf";
	int s1,s2;
	s1=memcmp(str1,str2,6);
	s2=memcmp(str1,str2,5);
	printf("The comparison fo 6 character\n");
	if(s1>0) printf("%s>%s\n",str1,str2);
	else if(s1<0) printf("%s<%s\n",str1,str2);
	else printf("%s=%s\n",str1,str2);
	printf("The comparison of 5 character\n");
	if(s2>0) printf("%s>%s\n",str1,str2);
	else if(s2<0) printf("%s<%s\n",str1,str2);
	else printf("%s=%s\n",str1,str2);
	return 0;
}*/

/*int main() {
	// 从source所指的对象中复制n个字符到destin所指的对象中。
	// 但是，如果这种复制发生在重叠对象之间，其行为是不可预知的。
	char *s="############";
	char d[]="This ia a test for memcpy function";
	printf("destination before memcpy:\n%s\n",d);
	memcpy(d,s,strlen(s)+1);
	printf("destination after memcpy:\n%s\n",d);
	//else printf("memcpy failed\n");
	return 0;
}*/

/*int main() {
	char *s="Golden Global View";
	char d[20];
	memcpy(d,s,(strlen(s)+1));
	printf("%s\n",d);
	getchar();
	return 0;
}*/

/*int main() {
	char *s="Golden Global View";
	char d[20];
	memcpy(d,s+14,4); //从第14个字符(V)开始复制，连续复制4个字符(View)
	//memcpy(d,s+14*sizeof(char),4*sizeof(char));也可
	d[4]='\0';
	printf("%s\n",d);
	return 0;
}*/

/*int main() {
	char src[] = "******************************";
	char dest[] = "abcdefghijlkmnopqrstuvwxyz0123as6";
	printf("destination before memcpy: %s\n", dest);
	memcpy(dest, src, strlen(src));
	printf("destination after memcpy: %s\n", dest);
	return 0;
}*/

/*int main() {
	// memmove:字块移动
	char s[]="##########";
	char d[]="This is a test for memcpy function";
	char *ptr;
	printf("destination before memmove:\n%s\n",d);
	ptr=(char*)memmove(d,s,strlen(s));
	if(ptr) printf("destiantion after memmove:\n%s\n",d);
	else printf("memcpy failed\n");
	return 0;
}*/

/*int main() {
	char d[]="1234567890";
	char *p;
	p=d+3;
	printf("%s\n",d);
	memmove(p,d,6);
	printf("%s\n",d);
	return 0;
}*/

/*int main() {
	// memset:字符加载
	char str[]="AAAAAAAAAAAAAAAAAAAA";
	printf("The original string is    :%s\n",str);
	memset(str,'B',9);
	printf("The string after memset is:%s\n",str);
	return 0;
}*/

/*int main() {
	// strchr:返回字符串中字符首次匹配的位置
	char str[15]={""};
	char *ptr,c='r';
	strcpy(str,"Hello,World");
	ptr=strchr(str,c);
	if(ptr) 
		printf("The character %c is at position:%d\n",c,ptr-str);
	else
		printf("The character was not found\n");
	return 0;
}*/

/*int main() {
	// strcspn:字符集逆匹配
	// 字符集逆匹配与字符集匹配两者的匹配方式截然相反，
	// 字符串匹配是当字符串中字符等于
	// 字符集中任意字符是匹配成功，
	// 字符串逆匹配是当字符串中字符不等于
	// 字符集中任意字符是匹配成功。
	char *str1="tomato",*str2="carrot";
	char *str="abc";
	int result;
	result=strcspn(str1,str);
	if(result)
		printf("The first %d is congruent\n",result);
	else printf("No character is congruent\n");
	result=strcspn(str2,str);
	if(result)
		printf("The first %d is congruent\n",result);
	else printf("No character is congruent\n");
	getchar();
	return 0;
}*/

/*int main() {
	// strdup:字符串新建拷贝
	char *src="This is the buffer text";
	char *dest;
	dest=strdup(src);
	printf("%s\n",dest);
	return 0;
}*/

/*#include"errno.h"
int main() {
	// strerror:字符串错误信息
	char *error;
	int i;
	for(i=0;i<12;i++) {
		error=strerror(i);
		printf("%s\n",error);
	}
	return 0;
}*/

// strlwr:字符串转换小写字符
// strncat:字符串连接 将src中前n个字符连接到dest
// char* strncat(char* dest,char* src,int n);

// strncmp:前n个字符串子串比较，区分大小写
// strncpy:将前n个字符串子串拷贝
// char* strncpy(char* dest,char* src,int n);

/*int main() {
	// strpbrk:字符集字符匹配
	// 在字符串中查找第一个属于字符集的字符位置，
	// 也就是在字符串str1中查找第一个属于字符集
	// str2中任意字符的位置。
	// char *strpbrk(char *str1, char *str2); 
	char *str1="These are 5 pigs in the hogpen";
	char *str2="0123456789";
	char *result;
	result=strpbrk(str1,str2);
	if(result) printf("%s\n",result++);
	else printf("These are no numbers any more");
	result=strpbrk(result,str2);
	if(result) printf("%s\n",result++);
	else printf("These are no numbers any more");
	getchar();
	return 0;
}*/

// strrev:字符串倒转
// strrchr:字符串中字符末次匹配,查找给定字符在字符串中最后一次出现的位置

/*int main() {
	// strset:字符串设定
	char str[11]="0123456789";
	char symbol='a';
	printf("Before:%s\n",str);
	strset(str,symbol);
	printf("After:%s\n",str);
	getchar();
	return 0;
}*/

/*int main() {
	// strspn:字符集匹配
	// int strspn(char *str1, char *str2);
	// 在字符串str1中查找第一个不属于字符集
	// str2中任何一个字符的下标
	char *str1="cabbage",*str2="potato";
	char *str="abc";
	int result;
	result=strspn(str1,str);
	if(result)
		printf("The first %d is congruent\n",result);
	else 
		printf("No character is congruent");
	return 0;
}*/

/*int main() {
	// strstr:字符串匹配 char *strstr(char *str1, char *str2);
	// 在字符串中查找另一个字符串首次出现的位置，
	// 也就是在字符串str1中查找第一次出现字符串str2的位置
	char *str1="Borland International",*str2="nation";
	char *result;
	result=strstr(str1,str2);
	if(result)
		printf("The substing is:%s\n",result);
	else 
		printf("Not found the substring");
	return 0;
}*/

// strtod:字符串转换成双精度函数
// strtol:字符串转换成长整型函数
// strtoul:字符串转换成无符号长整型函数
// strupr:字符串大写转换函数
// strupr:字符串大写转换函数

int main() {
	// strtok:字符串分隔函数 char* strstr(char* str1,char* str2);
	// 在字符串中查找单词，这个单词始有第二个字符串中
	// 定义的分隔符分开，也就是在字符串str1中查找由
	// 字符串str2定义的分隔符，以分隔符为界，
	// 分隔出来的分隔符前面的所有字符组成一个单词，
	// 分离出第一个单词后将第一个参数置为空，
	// 可以继续分隔第二个单词。
	char str1[]="I am very \thappy,to,study\nC\nprogramme";
	char str2[]=",\t\n",*token;
	printf("%s\n\nTokens:\n",str1);
	token=strtok(str1,str2);
	while(token!=NULL) {
		printf("%s\n",token);
		token=strtok(NULL,str2);
	}
	getchar();
	return 0;
}