#include<iostream.h>
#define   PI   3.1416
main()  {
    int i=100;
#if 1
    cout<<"i="<<i<<endl;
#endif

#ifdef PI
    cout<<"1  PI="<<PI<<endl;
#endif

#ifndef PI
    cout<<"2  PI="<<PI<<endl;   //此语句不被编译执行
#endif
}
