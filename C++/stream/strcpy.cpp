#include"stdio.h"
#include"stdlib.h"
#include"string.h"
//#include"alloc.h"

/*int main() {
	char str1[13],ch='s',*p;
	strcpy(str1,"liangjisheng");
	p=strchr(str1,ch);
	printf("%s\n",p);
	return 0;
}*/

/*int main() {
	// 将一个串与另一个串比较，区分大小写
	char *buf1="aaa",*buf2="bbb",*buf3="ccc";
	int ptr;
	ptr=strcmp(buf2,buf1);
	if(ptr>0) printf("buffer2 is biger than buffer1\n");
	else if(ptr==0) printf("buffer2 is equal than buffer1\n");
	else printf("buffer2 is less than buffer1\n");

	ptr=strcmp(buf2,buf3);
	if(ptr>0) printf("buffer2 is bigger than buffer3\n");
	else if(ptr==0) printf("buffer2 is equal than buffer3\n");
	else printf("buffer2 is less than buffer3\n");

	return 0;
}*/

/*int main() {
	// 将一个串与另一个串比较，不区分大小写
	char *buf1="BBB",*buf2="bbb";
	int ptr=strcmpi(buf2,buf1);
	if(ptr>0) printf("buffer2 is bigger than buffer1\n");
	else if(ptr==0) printf("buffer 2 is equal than buffer 1\n");
	else printf("buffer 2 is less than buffer 1\n");
	return 0;
}*/

/*int main() {
	// 在串中查找第一个给定的字符集内容的段
	char *str1="1234567890",*str2="747DC8";
	int length=strcspn(str1,str2);
	printf("Character where str intersect is at position %d\n",length);
	return 0;
}*/

/*int main() {
	// 将串拷贝到新建的位置处
	char *str1,*str2="abcde";
	str1=strdup(str2);
	printf("%s\n",str1);
	free(str1);
	return 0;
}*/

// stricmp 不区分大小写比较两个串

/*int main() {
	// 返回指向错误信息字符串的指针
	char *buffer;
	buffer=strerror(errno);
	printf("Error:%s\n",buffer);

	return 0;
}*/

/*int main() {
	// 比较两个串的前n个字符大小，区分大小写
	char *buf1="aaabbb",*buf2="bbbccc",*buf3="ccc";
	int ptr;
	ptr=strncmp(buf2,buf1,3);
	if(ptr>0) printf("buffer 2 is greater than buffer1 \n");
	else if(ptr==0) printf("buffer 2 is equal than buffer 1\n");
	else printf("buffer 2 si less than buffer 1\n");

	return 0;
}*/

// strncmpi，strnicmp 比较两个串的前n个字符大小，不区分大小写

/*int main() {
	// 复制一个串的前n个字符到另一个串中
	char str[10],*buf="abcdefghi";
	strncpy(str,buf,4);
	str[4]='\0';
	printf("%s\n",str);

	return 0;
}*/

/*int main() {
	// 将一个字符串的前n个字符设置为指定的字符
	char str[]="abcdefghijklmnopqrstuvwxyz";
	char letter='x';
	printf("string before strnset:%s\n",str);
	strnset(str,letter,13);
	printf("string after strnset:%s\n",str);

	return 0;
}*/

/*int main() {
	// 在str1中查找str2中任意一个字符第一次出现的位置
	char *str1="abcdefghijklmnopqrstuvwxyz";
	char *str2="onm",*ptr;
	ptr=strpbrk(str1,str2);
	if(ptr) printf("strpbrk found first character:%c\n",*ptr);
	else printf("strpbrk didn't find character in set\n");
	return 0;
}*/

/*int main() {
	// 查找在str中字符c最后一次出现的位置
	char str[15],*ptr,c='r';
	strcpy(str,"This is a string");
	ptr=strrchr(str,c);
	if(ptr) printf("The character %c is at position:%d\n",c,ptr-str);
	else printf("The character was not found\n");
	return 0;
}*/

/*int main() {
	// 字符串倒转
	char str[]="string"; // 如果写成char *str="string"; 则会报错
	// str这个指针在栈上，而它指向的对象则存储在内存中的常量存储区
	printf("Before strrev():%s\n",str);
	strrev(str);
	printf("After strrev():%s\n",str);
	return 0;
}*/

/*int main() {
	// 在str2中查找与str1第一次出现不同的位置
	char *str1="1234567890";
	char *str2="123DC8";
	int length=strspn(str1,str2);
	printf("Character where strings differ is at position:%d\n",length);
	return 0;
}*/

/*int main() {
	// 在str1中查找str2第一次出现的位置
	char *str1="Borland International",*str2="nation",*ptr;
	ptr=strstr(str1,str2);
	printf("The substring is:%s\n",ptr);
	return 0;
}*/

/*int main() {
	// 将字符串转换成double型值
	char input[80],*endptr;
	double d;
	printf("Enter a floatint point number:");
	gets(input);
	d=strtod(input,&endptr);
	printf("The string is:%s the number is:%lf\n",input,d);
	return 0;
}*/

/*int main() {
	// 查找在第二个串中指定的分界符分隔开的单词
	char input[16]="abc,d";
	char *p;
	// strtok places a NULL terminator in front of the token,if found
	p=strtok(input,",");
	if(p) printf("%s\n",p);
	// A second call to strtok using a NULL 
	// as the first parameter returns a pointer
	// to the character following the token
	p=strtok(NULL,",");
	if(p) printf("%s\n",p);
	return 0;
}*/

// strtol 将串转换成长整数
// strupr 将串中的小写字母转换成大写字母

/*int main() {
	// 交换字节
	char str1[15]="rFna koBlrna d",target[15];
	swab(str1,target,strlen(str1));
	printf("This is target:%s\n",target);
	return 0;
}*/

// strcpy() and memcpy()
/*typedef struct {
	int id;
	char last_name[20];
	char first_name[15];
}CUSTREC;

int main() {
	char *src_string="This is the source string";
	char dest_string[50];
	CUSTREC src_cust,dest_cust;
	printf("Hello! I'm going to copy src_string into dest_string!\n");
	printf("Done! dest_string is:%s\n",strcpy(dest_string,src_string));
	printf("Encore! Let's copy one CUSTREC to another.\n");
	printf("I'll copy src_cust into dest_cust.\n");
	// First intialize the src_cust data members
	src_cust.id=1;
	strcpy(src_cust.last_name,"Strahan");
	strcpy(src_cust.first_name,"Troy");
	memcpy(&dest_cust,&src_cust,sizeof(CUSTREC));
	printf("Done! I just copied customer number #%d(%s%s)\n",
		dest_cust.id,dest_cust.first_name,dest_cust.last_name);
	return 0;
}*/