#include<iostream.h>
main()
{
    //�������顢������ָ�����
    int a[]={1,2,3,4,5,6};
    int *ip1,*ip2;

    //����ָ��ĸ�ֵ����
    ip1=a;
    ip2=ip1;   
    cout<<"*ip1="<<(*ip1)<<endl;
    cout<<"*ip2="<<(*ip2)<<endl;

    //����ָ��������Լ�������������
    ip1++;  
    ip2+=4; 
    cout<<"*ip1="<<(*ip1)<<endl;
    cout<<"*ip2="<<(*ip2)<<endl;
    
    //����ָ�����֮��Ĺ�ϵ����
    int n=ip2>ip1;
    cout<<"ip2>ip1="<<n<<endl;
    cout<<"ip2!=NULL="<<(ip2!=NULL)<<endl;

    //ָ�����֮��ļ���
    n=ip2-ip1;
    cout<<"ip2-ip1="<<n<<endl;
}
