#include <iostream.h>
main()
{
    //�� sizeof ��������ֳ������ֽڳ���
    cout<<"sizeof('$')="<<sizeof('$')<<endl;
    cout<<"sizeof(1)="<<sizeof(1)<<endl;
    cout<<"sizeof(1.5)="<<sizeof(1.5)<<endl;
    cout<<"sizeof(\"Good!\")="<<sizeof("Good!")<<endl;

    //��sizeof ��������ͱ������ֽڳ���
    int i=100;
    char c='A';
    float x=3.1416; 
    double p=0.1;
    cout<<"sizeof(i)="<<sizeof(i)<<endl;
    cout<<"sizeof(c)="<<sizeof(c)<<endl;
    cout<<"sizeof(x)="<<sizeof(x)<<endl;
    cout<<"sizeof(p)="<<sizeof(p)<<endl;

    //��sizeof ������ʽ���ֽڳ���
    cout<<"sizeof(x+1.732)="<<sizeof(x+1.732)<<endl;

    //�� sizeof ��������͵��ֽڳ���
    cout<<"sizeof(char)="<<sizeof(char)<<endl;
    cout<<"sizeof(int)="<<sizeof(int)<<endl;
    cout<<"sizeof(float)="<<sizeof(float)<<endl;
    cout<<"sizeof(double)="<<sizeof(double)<<endl;

    //��sizeof ����������ֽڳ���
    char str[]="This is a test.";
    int a[10];	
    double xy[10];
    cout<<"sizeof(str)="<<sizeof(str)<<endl;
    cout<<"sizeof(a)="<<sizeof(a)<<endl;
    cout<<"sizeof(xy)="<<sizeof(xy)<<endl;

    //��sizeof �����Զ������͵ĳ���
    struct st {
        short num;
        float math_grade;
        float Chinese_grade;
        float sum_grade;
    };
    st student1;
    cout<<"sizeof(st)="<<sizeof(st)<<endl;
    cout<<"sizeof(student1)="<<sizeof(student1)<<endl;
}
