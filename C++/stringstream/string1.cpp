#include"iostream"
#include <errno.h>
#include"string.h"
#include"stdio.h"
#include"cstring"
using namespace std;


/*int main() {
	unsigned int a[5];
	memset((void*)a,'1',5*sizeof(int));
	for(int i=0;i<5;i++) {
		cout<<(int)(a[i]&1)<<" ";
	}
	cout<<endl;
	return 0;
}*/


//#include <alloc.h>
// strcspn
// �� ��: ��string1���������string2���κ�һ���ַ���һ�γ��ֵ�λ��
/*int main(void)
{
	char *string1 = "1234567890";
	char *string2 = "747DC8";
	int length;
	length = strcspn(string1, string2);
	printf("Character where strings intersect is at position %d\n", length);
	return 0;
}*/

// strerror
// �� ��: ����ָ�������Ϣ�ַ�����ָ��
// �� ��: char *strerror(int errnum);
/*int main(void)
{
	char *buffer;
	int error=1;
	buffer = strerror(error);
	printf("Error: %s\n", buffer);
	return 0;
}*/

// ������: strnset
// �� ��: ��һ������ǰn���ַ�����Ϊָ���ַ�
// �� ��: char *strnset(char *str, char ch, unsigned n);

// strpbrk
// �� ��: ��str1�в���str2�г��ֵĵ�һ���ַ�
// �� ��: char *strpbrk(char *str1, char *str2);
/*int main(void)
{
	char *string1 = "abcdefghijklmnopqrstuvwxyz";
	char *string2 = "onm";
	char *ptr;
	ptr = strpbrk(string1, string2);
	if (ptr)
		printf("strpbrk found first character: %c\n", *ptr);
	else
		printf("strpbrk didn't find character in set\n");
	return 0;
}*/

// ������: strrchr
// �� ��: �ڴ��в���ָ���ַ������һ�����ֵ�λ��
// �� ��: char *strrchr(char *str, char c);

/*#include <string.h>
#include <stdio.h>
int main(void)
{
	char string[15];
	char *ptr, c = 'r';
	strcpy(string, "This is a string");
	ptr = strrchr(string, c);
	if (ptr)
		printf("The character %c is at position: %d\n", c, ptr-string);
	else
		printf("The character was not found\n");
	return 0;
}*/

// strspn
// �� ��: ��str1�в�����str2���ַ���һ����ͬ��λ��
// �� ��: int strspn(char *str1, char *str2);
/*int main(void)
{
	char *string1 = "1234567890";
	char *string2 = "123DC8";
	int length;
	length = strspn(string1, string2);
	printf("Character where strings differ is at position %d\n", length);
	return 0;
}*/

// ������: strstr
// �� ��: �ڴ��в���ָ���ַ����ĵ�һ�γ���
// �� ��: char *strstr(char *str1, char *str2);
/*int main(void)
{
	char *str1 = "Borland International", *str2 = "nation", *ptr;
	ptr = strstr(str1, str2);
	printf("The substring is: %s\n", ptr);
	return 0;
}*/

// ������: strtod
// �� ��: ���ַ���ת��Ϊdouble��ֵ
// �� ��: double strtod(char *str, char **endptr);
/*int main(void)
{
	char input[80], *endptr;
	double value;
	printf("Enter a floating point number:");
	gets(input);
	value = strtod(input, &endptr);
	printf("The string is %s the number is %lf\n", input, value);
	return 0;
}*/

// ������: strtok
// �� ��: �������ڵڶ�������ָ���ķֽ���ָ����ĵ���
// �� ��: char *strtok(char *str1, char *str2);
/*int main(void)
{
	char input[16] = "abc,d";
	char *p;	
	p = strtok(input, ",");
	if (p) printf("%s\n", p);
	p = strtok(NULL, ",");
	if (p) printf("%s\n", p);
	return 0;
}*/

// ������: strtol
// �� ��: ����ת��Ϊ������
// �� ��: long strtol(char *str, char **endptr, int base);

/*
int main(void)
{
	char *string = "87654321", *endptr;
	long lnumber;
	
	lnumber = strtol(string, &endptr, 10);
	printf("string = %s long = %ld\n", string, lnumber);
	return 0;
}*/

// ������: strupr
// �� ��: �����е�Сд��ĸת��Ϊ��д��ĸ
// �� ��: char *strupr(char *str);
/*int main(void)
{
	char *string = "abcdefghijklmnopqrstuvwxyz";	
	printf("%s\n",strupr(string));
	return 0;
}*/

// ������: swab
// �� ��: �����ֽ�
// �� ��: void swab (char *from, char *to, int nbytes);
/*char source[15] = "rFna koBlrna d";
char target[15];
int main(void)
{
	swab(source, target, strlen(source));
	printf("This is target: %s\n", target);
	return 0;
}*/