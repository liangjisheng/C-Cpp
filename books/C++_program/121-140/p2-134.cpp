#include<iostream.h>
int extract_int()
{
    char ch;
    int n=0;
    while(ch=cin.get())
        if (ch>='0' && ch<='9')
        {
            cin.putback(ch);
            cin>>n;
            break;
        }
    return n;
}
//main()����
main(void)
{
    //��ȡ�ַ����е�����
    int a=extract_int();
    int b=extract_int();
    int c=extract_int();
 
    //��ʾ���
    cout<<a<<"+"<<b<<"="<<c<<endl;
}
