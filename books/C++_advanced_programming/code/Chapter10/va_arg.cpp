#include <iostream>
#include <cstdio>
#include <cstdarg>
using namespace std;

void printInts(int num,...)
{
    int temp;
    va_list ap;
    va_start(ap,num);
    for(int i = 0;i < num; ++i){
        temp = va_arg(ap,int);
        cout << temp << " ";
    }
    va_end(ap);
    cout << endl;
}

int main()
{
    printInts(5,1,2,3,4,5);

    return 0;
}
