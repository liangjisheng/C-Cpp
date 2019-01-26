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
//main()函数
main(void)
{
    //提取字符串中的数字
    int a=extract_int();
    int b=extract_int();
    int c=extract_int();
 
    //显示结果
    cout<<a<<"+"<<b<<"="<<c<<endl;
}
