#include"stdio.h"
#include"stdlib.h"
#include"string.h"

/*int main() {
	// atof:�ַ���ת�����ͺ���
	char *str="12345.67";
	float result;
	result=atof(str);
	printf("string=%s\nfloat=%f\n",str,result);
	getchar();
	return 0;
}*/

/*int main() {
	// atoi:�ַ���ת����
	char *str="12345.67";
	int result;
	result=atoi(str);
	printf("string=%s\ninteger=%d\n",str,result);
	getchar();
	return 0;
}*/
// atol:�ַ���ת������

/*int main() {
	// memchr:�ַ���������,��strǰstrlen(str)���ַ�������C��һ�γ��ֵ�λ��
	char *str="I love China\n";
	char *p;
	p=(char*)memchr(str,'C',strlen(str));
	if(p) printf("%s\n",p);
	else printf("The character was not found\n");
	return 0;
}*/

/*int main() {
	// memcmp:�ַ����Ƚ�
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
	// ��source��ָ�Ķ����и���n���ַ���destin��ָ�Ķ����С�
	// ���ǣ�������ָ��Ʒ������ص�����֮�䣬����Ϊ�ǲ���Ԥ֪�ġ�
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
	memcpy(d,s+14,4); //�ӵ�14���ַ�(V)��ʼ���ƣ���������4���ַ�(View)
	//memcpy(d,s+14*sizeof(char),4*sizeof(char));Ҳ��
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
	// memmove:�ֿ��ƶ�
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
	// memset:�ַ�����
	char str[]="AAAAAAAAAAAAAAAAAAAA";
	printf("The original string is    :%s\n",str);
	memset(str,'B',9);
	printf("The string after memset is:%s\n",str);
	return 0;
}*/

/*int main() {
	// strchr:�����ַ������ַ��״�ƥ���λ��
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
	// strcspn:�ַ�����ƥ��
	// �ַ�����ƥ�����ַ���ƥ�����ߵ�ƥ�䷽ʽ��Ȼ�෴��
	// �ַ���ƥ���ǵ��ַ������ַ�����
	// �ַ����������ַ���ƥ��ɹ���
	// �ַ�����ƥ���ǵ��ַ������ַ�������
	// �ַ����������ַ���ƥ��ɹ���
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
	// strdup:�ַ����½�����
	char *src="This is the buffer text";
	char *dest;
	dest=strdup(src);
	printf("%s\n",dest);
	return 0;
}*/

/*#include"errno.h"
int main() {
	// strerror:�ַ���������Ϣ
	char *error;
	int i;
	for(i=0;i<12;i++) {
		error=strerror(i);
		printf("%s\n",error);
	}
	return 0;
}*/

// strlwr:�ַ���ת��Сд�ַ�
// strncat:�ַ������� ��src��ǰn���ַ����ӵ�dest
// char* strncat(char* dest,char* src,int n);

// strncmp:ǰn���ַ����Ӵ��Ƚϣ����ִ�Сд
// strncpy:��ǰn���ַ����Ӵ�����
// char* strncpy(char* dest,char* src,int n);

/*int main() {
	// strpbrk:�ַ����ַ�ƥ��
	// ���ַ����в��ҵ�һ�������ַ������ַ�λ�ã�
	// Ҳ�������ַ���str1�в��ҵ�һ�������ַ���
	// str2�������ַ���λ�á�
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

// strrev:�ַ�����ת
// strrchr:�ַ������ַ�ĩ��ƥ��,���Ҹ����ַ����ַ��������һ�γ��ֵ�λ��

/*int main() {
	// strset:�ַ����趨
	char str[11]="0123456789";
	char symbol='a';
	printf("Before:%s\n",str);
	strset(str,symbol);
	printf("After:%s\n",str);
	getchar();
	return 0;
}*/

/*int main() {
	// strspn:�ַ���ƥ��
	// int strspn(char *str1, char *str2);
	// ���ַ���str1�в��ҵ�һ���������ַ���
	// str2���κ�һ���ַ����±�
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
	// strstr:�ַ���ƥ�� char *strstr(char *str1, char *str2);
	// ���ַ����в�����һ���ַ����״γ��ֵ�λ�ã�
	// Ҳ�������ַ���str1�в��ҵ�һ�γ����ַ���str2��λ��
	char *str1="Borland International",*str2="nation";
	char *result;
	result=strstr(str1,str2);
	if(result)
		printf("The substing is:%s\n",result);
	else 
		printf("Not found the substring");
	return 0;
}*/

// strtod:�ַ���ת����˫���Ⱥ���
// strtol:�ַ���ת���ɳ����ͺ���
// strtoul:�ַ���ת�����޷��ų����ͺ���
// strupr:�ַ�����дת������
// strupr:�ַ�����дת������

int main() {
	// strtok:�ַ����ָ����� char* strstr(char* str1,char* str2);
	// ���ַ����в��ҵ��ʣ��������ʼ�еڶ����ַ�����
	// ����ķָ����ֿ���Ҳ�������ַ���str1�в�����
	// �ַ���str2����ķָ������Էָ���Ϊ�磬
	// �ָ������ķָ���ǰ��������ַ����һ�����ʣ�
	// �������һ�����ʺ󽫵�һ��������Ϊ�գ�
	// ���Լ����ָ��ڶ������ʡ�
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