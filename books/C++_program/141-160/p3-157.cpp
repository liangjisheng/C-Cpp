#include<stdio.h>
main()
{
    //�����ַ���
    char str[80];
    printf("str:");  	//��ʾ��ʾ
    scanf("%s",str);
    printf("The string:%s",str); 

    //�������������
    int a,b,c,sum;
    printf("\na\tb\tc\n");        	//��ʾ��ʾ
    scanf("%d %o %x",&a,&b,&c); 	//��ʮ���ơ��˽��ơ�ʮ��������ʽ��������
    sum=a+b+c;
    printf("a=%d  b=%d  c=%d   sum=%d",a,b,c,sum);

    //���븡������������ʾ
    float x,y;          	//��������
    printf("\nx\ty\n");        	//��ʾ��ʾ
    scanf("%f %f",&x,&y);     	//�Էǿհ��ַ�"x= y="���룬������
    printf("sum=%f  product=%f\n",x+y, x*y);   //��ʾ���ʽ��ֵ
}
