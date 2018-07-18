#include"stdio.h"
#include"stdlib.h"
#include"limits.h"
#include"string.h"

/*int main() {
	// 将整数转换成字符串
	int num=100;
	char str[25];
	itoa(num,str,10);
	printf("The number is %d and the string is %s\n",num,str);
	return 0;
}*/

/*int main() {
	// 将整数转换成字符串
	int num=100;
	char str[25];
	sprintf(str,"%d",num);
	printf("The string is %s\n",str);
	return 0;
}*/

/*int main() {
	// 将浮点型转换成字符串
	// ecvt() 将双精度值转换成字符串，转换结果中不包括小数点
	// gcvt() 将双精度值转换成字符串，转换结果中包括小数点
	double num=12345.678;
	char *str;
	int dec_pl,sign,ndigits=3;
	str=fcvt(num,ndigits,&dec_pl,&sign);
	printf("Original number is: %f\n",num);
	printf("Converted string is: %s\n",str);
	printf("Decimal place is: %d\n",dec_pl);
	printf("Sign: %d\n",sign);
	return 0;
}*/

// atoi()		将字符串转换成整数
// atof()		将字符串转换为双精度浮点型值
// atoi()		将字符串转换为整型值
// atol()		将字符串转换为长整型值
// strtod()		将字符串转换为双精度浮点型值，并报告不能被转换的所有剩余数字
// strtol()		将字符串转换为长整值，并报告不能被转换的所有剩余数字
// strtoul()	将字符串转换为无符号长整型值，并报告不能被转换的所有剩余数字

/*int main() {
	char *str="1234567891011121314151617181920";
	unsigned long num;
	char *leftover;
	num=strtoul(str,&leftover,10);
	printf("Original string:%s\n",str);
	printf("Converted number:%lu\n",num);
	printf("Leftover characters:%s\n",leftover);
	return 0;
}*/

int main() {
	char *source_str="THIS IS THE SOURCE STRING";
	printf("First 11 characters:%11.lls\n",source_str);
	printf("Last 13 characters:%13.13\n",
		source_str+(strlen(source_str)-13));
	return 0;
}