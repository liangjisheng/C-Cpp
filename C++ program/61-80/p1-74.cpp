#include<iostream.h>
//����ԭ�����
int  abs(int x);
long abs(long x);
float abs(float x);

//main()�����Ķ���
void main(void) 
{
    //��������
    int i1=32767,i2=-32767;
    long l1=456789,l2=-456789;
    float x1=1.1234,x2=-1.1234;
   
    //ֱ����cout����е��ú���
    cout<<abs(i1)<<","<<abs(i2)<<endl;
    cout<<abs(l1)<<","<<abs(l2)<<endl;
    cout<<abs(x1)<<","<<abs(x2)<<endl;
}

//����int�͵�abs()����
int abs(int x) {
    if (x<0)
       return(-x);
    else
       return(x);
}

//����long�͵�abs()���� 
long abs(long x) {
    if (x<0)
       return(-x);
    else
        return(x);
}

//����float�� abs����
float abs(float x) {
    if (x<0.0)
       return(-x);
    else
       return(x);
}
