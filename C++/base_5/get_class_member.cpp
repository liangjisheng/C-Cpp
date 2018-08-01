#include <iostream>
#include"padding.h"
#include"stdlib.h"
using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    padding a;
    cout<<"sizeof(padding)="<<sizeof(padding)<<endl;
    cout<<"(sizeof(char)+sizeof(int)+sizeof(double))="
        <<(sizeof(char)+sizeof(int)+sizeof(double))<<endl;

    char* p=(char*)(&a);
    int int_len=sizeof(int);
    cout<<"1st element: "<<*p<<endl;
    cout<<"2nd element: "<<*(int*)(p+int_len)<<endl;
    cout<<"3rd element: "<<*(double*)(p+(int_len<<1))<<endl;

    system("pause");
    return 0;
}
