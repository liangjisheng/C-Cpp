#include<iostream.h>
#include<stdlib.h>
#define MAX 30
//main()�Ķ���
int main(void)
{
    char str[MAX];

    //�ַ���ת��Ϊint��long��������
    cout<<"Please input a string:"<<endl;
    cin>>str;
    int n=atoi(str);
    cout<<"n="<<n<<endl;
    long l=atol(str);
    cout<<"l="<<l<<endl;
  
    //�ַ���ת��Ϊdouble����
    cout<<"Please input a string:"<<endl;
    cin>>str;
    double x=atof(str);
    cout<<"x="<<x<<endl;
	
    return 0;
}
