#include<iostream.h>
#include <stdlib.h>
#include <time.h>

//�������[n1,n2]��Χint������ĺ���
int rand(int n1,int n2) {
    if (n1>n2) return -1;
    if (n1==n2) return 0;
    int temp=n1+int((n2-n1)*double(rand())/RAND_MAX);
    return temp;
}

//main()�����Ķ��壬�ӷ���ϰ����
void main( void )
{
     int i;

    //ʹ�õ�ǰ��ϵͳʱ���ʼ�����������
    srand( (unsigned)time( NULL ) );

    //�ӷ���ϰ
    int a,b,c;
    do {
        a=rand(0,20);
        b=rand(0,20);
L1:     cout<<a<<"+"<<b<<"=";
        cin>>c;
        if (c==0) break;
        if (c!=a+b) {
            cout<<"Error! Try again!"<<endl;
            goto L1;
        } 
        cout<<"OK!"<<endl;
    } while (1);

}
