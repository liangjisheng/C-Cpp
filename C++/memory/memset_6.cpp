#include <stdio.h>  
#include <string.h>  

#define BUFF_LEN 11					// 12 may fix the Run-Time Check Failure #2  

int rtc_option_test(char * pStr);  

int main()  
{  
	char * myStr = "hello world";  
	rtc_option_test(myStr);
	printf("%s\n", myStr);

	getchar();
	return 0;  
}

int rtc_option_test(char * pStr)  
{  
	char buff[BUFF_LEN] = {0};  
	strcpy(buff, pStr);				//cause Run-Time Check Failure #2 - Stack around  
									//the variable 'buff' was corrupted.  
	return 0;  
}  