#include<iostream.h>
//����ԭ��������������
//����main()���� 
main()  
{
    //max()����ԭ���������
    float max(float,float);
	
    //�����������
    float a,b,Max;

    //�������������
    cout<<"a=";
    cin>>a;
    cout<<"b=";
    cin>>b;
    Max=max(a,b);     //����max()���� 
    cout<<"max("<<a<<","<<b<<")="<<Max<<endl;
}
//����max()����
float max(float x,float y)     //max()����ֵ����Ϊ������
{
    float z;
    z=(x>y)?x:y;
    return(z);
}

