#include<iostream.h>
#include<direct.h>
#include<errno.h>
#define MAX_PATH 250
main()
{
    //��������
    char *p,str[MAX_PATH];

    //������Ŀ¼
    if (mkdir("d:\\ABC")){
        cout<<"mkdir Error!"<<endl;
    }

    //���ù���Ŀ¼
    if (chdir("d:\\ABC")){
        cout<<"chdir Error!"<<endl;
    }

    //��ȡ��ǰĿ¼
    if ((p=getcwd(str,MAX_PATH))==NULL) {
        cout<<"getcwd Error!"<<endl;
    }
    else
    {
        cout<<"p:"<<p<<endl;
        cout<<"str:"<<str<<endl;
    }

    //���ù���Ŀ¼
    if (chdir("d:\\")){
        cout<<"chdir Error!"<<endl;
    }

    //ɾ��ָ��Ŀ¼
    if (rmdir("d:\\ABC")==-1) 
        cout<<"rmdir Error!"<<endl;
}
