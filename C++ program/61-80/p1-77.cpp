#include<iostream.h>
//��������main()����
int main(int argc,char *argv[])
{
    int i;
    for(i=0;i<argc;i++)
       cout<<i<<":"<<argv[i]<<endl;
    return 0;
}
