#include<iostream.h>

//����Ϊ����ָ��ĺ���
int get_result(int a, int b, int (*sub)(int,int))
{
    int r;
    r=sub(a,b);
    return r;
}
 
//�������ֵ
int max(int a, int b)
{
    cout<<"In max"<<endl;
    return((a > b) ? a: b);
}

//������Сֵ
int min(int a, int b)
{
    cout<<"In min"<<endl;
    return((a < b) ? a: b);
}

//���
int sum(int a, int b)
{
    cout<<"In sum"<<endl;
    return(a+b);
}

//����ָ������ָ��
void main(void)
{
    int a,b,result;

    //����3��
    for (int i=1;i<=3;i++) {
        cout<<"Input a and b :";
        cin>>a>>b;

		cout<<i<<"\tget_result("<<a<<","<<b<<", &max):"<<endl;
        result =get_result(a, b, &max);
        cout<<"Max of "<<a<<" and "<<b<<" is "<<result<<endl;
   
        result = get_result(a, b, &min);
        cout<<"Min of "<<a<<" and "<<b<<" is "<<result<<endl;

        result = get_result(a, b, &sum);
        cout<<"Sum of "<<a<<" and "<<b<<" is "<<result<<endl; 
    }
}
