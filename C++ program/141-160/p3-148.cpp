#include<iostream.h>
#include <stdlib.h>
#include <math.h>

//main()�����Ķ���
void main( void )
{
    double y;
    int N;
    //����һ�����ڵ���0����
    do {
        cout<<"N=";
        cin>>N;
        if (N>=0) break;
    } while (1);

    //���㲢��ʾ
    for(int i=0;i<=N;i++){
        y=pow(2,i);
        cout<<"pow("<<2<<","<<i<<")="<<y<<endl;
    }
}
