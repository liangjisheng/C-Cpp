#include<iostream.h>
#include<direct.h>
#include<errno.h>
#define MAX_PATH 250
main()
{
    //声明变量
    char *p,str[MAX_PATH];

    //设置新目录
    if (mkdir("d:\\ABC")){
        cout<<"mkdir Error!"<<endl;
    }

    //更该工作目录
    if (chdir("d:\\ABC")){
        cout<<"chdir Error!"<<endl;
    }

    //读取当前目录
    if ((p=getcwd(str,MAX_PATH))==NULL) {
        cout<<"getcwd Error!"<<endl;
    }
    else
    {
        cout<<"p:"<<p<<endl;
        cout<<"str:"<<str<<endl;
    }

    //更该工作目录
    if (chdir("d:\\")){
        cout<<"chdir Error!"<<endl;
    }

    //删除指定目录
    if (rmdir("d:\\ABC")==-1) 
        cout<<"rmdir Error!"<<endl;
}
