#include"stdio.h"
#include"stdlib.h"
#include"limits.h"
#include"string.h"

/*int main() {
	// ������ת�����ַ���
	int num=100;
	char str[25];
	itoa(num,str,10);
	printf("The number is %d and the string is %s\n",num,str);
	return 0;
}*/

/*int main() {
	// ������ת�����ַ���
	int num=100;
	char str[25];
	sprintf(str,"%d",num);
	printf("The string is %s\n",str);
	return 0;
}*/

/*int main() {
	// ��������ת�����ַ���
	// ecvt() ��˫����ֵת�����ַ�����ת������в�����С����
	// gcvt() ��˫����ֵת�����ַ�����ת������а���С����
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

// atoi()		���ַ���ת��������
// atof()		���ַ���ת��Ϊ˫���ȸ�����ֵ
// atoi()		���ַ���ת��Ϊ����ֵ
// atol()		���ַ���ת��Ϊ������ֵ
// strtod()		���ַ���ת��Ϊ˫���ȸ�����ֵ�������治�ܱ�ת��������ʣ������
// strtol()		���ַ���ת��Ϊ����ֵ�������治�ܱ�ת��������ʣ������
// strtoul()	���ַ���ת��Ϊ�޷��ų�����ֵ�������治�ܱ�ת��������ʣ������

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