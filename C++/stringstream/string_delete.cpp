#include"stdio.h"
#include"string.h"

int main()
{
	char str[]="askdaskaskdaskg";
	char del_str[]="ask";
	printf("Ô´×Ö·û´®:%s\n",str);
	printf("É¾³ýµÄ×Ö·û´®:%s\n",del_str);
	char* p=str;
	char* dp=del_str;
	int del_len=strlen(del_str);
	int i=0,j=0,k;
	while(unsigned(i)<strlen(str)) {
		while(*p++==*dp++ && j++<del_len);
		if(j==del_len) {
			k=i;
			j=k+del_len;
			while(str[j]!=NULL) {
				str[k++]=str[j++];
			}
			str[k]='\0';
		}
		else i++;
		p=&str[i]; dp=del_str;
		j=0;
	}
	printf("É¾³ýºóµÄ×Ö·û´®:%s\n",str);

	return 0;
}