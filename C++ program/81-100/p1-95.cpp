#include<stdio.h>
#include<stdlib.h>
#include<iostream.h>
int main(void) 
{ 
    //��������
    char ch;
    char str[20];
    int n;
    float x;

    //��stdin�Ӽ�������������
    fprintf(stdout,"ch str\n");
    fscanf(stdin,"%c %s",&ch,str);
    fprintf(stdout,"n    x \n");
    fscanf(stdin,"%d  %f",&n,&x);
    cout<<"----------------"<<endl;

    //�����ʾ
    fprintf(stdout,"ch=%c str=%s",ch,str);
    fprintf(stdout,"\nn=%d x=%f",n,x);
    cout<<endl;
}
