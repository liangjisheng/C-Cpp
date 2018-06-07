#include <iostream.h>
main()
{
    //声明变量语句中使用顺序运算
    int x, y;

    //计算中使用顺序运算
    x=50; 
    y=(x=x-5, x/5); 
    cout<<"x="<<x<<endl;
    cout<<"y="<<y<<endl;
}
