/*#include"stdio.h"
#include"string.h"
char* rtrim(char*);

int main() {
	char trail_str[]="This string has trailing spaces in it    ";
	printf("before calling rtrim(),trail_str is %s\n",trail_str);
	printf(" and has s legth of %d\n",strlen(trail_str));
	rtrim(trail_str);
	printf("after calling rtrim(),trail_str is %s\n",trail_str);
	printf(" and has s legth of %d\n",strlen(trail_str));
	return 0;
}

char* rtrim(char* str) {
	int n=strlen(str)-1;
	while(n>0) {
		if(*(str+n)==' ') *(str+n)='\0';
		else break;
		n--;
	}
	return str;
}*/