#include <iostream.h>
//�����ַ������ȵĺ���
int str_len(const char *string)
{
    //char *temp=string; ���뱨��
    //*string='x';       ���뱨��
    int i=0;
    while (*(string+i)!=NULL) 
        i++;
    return i;
}

//main()�����в���str_len()
void main()
{
    char a[]="ABCDE";
    cout<<a<<"\t"<<str_len(a)<<endl;
    char *str="Hello!";
    cout<<str<<"\t"<<str_len(str)<<endl;
    cout<<"This is a test."<<"\t"<<str_len("This is a test.")<<endl;
}
