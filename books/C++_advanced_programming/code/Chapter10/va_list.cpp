#include <iostream>
#include <cstdarg>
#include <cstdio>
using namespace std;

bool debug = false;

void debugOut(const char* str,...){
    va_list ap;
    if(debug){
        va_start(ap,str);
        vfprintf(stderr,str,ap);
        va_end(ap);     // 确保函数结束后，堆栈处于稳定状态
    }
}

int main()
{
    debug = true;
    debugOut("int %d\n",5);
    debugOut("String %s and int %d\n","hello",5);
    debugOut("Many ints: %d,%d,%d,%d,%d\n",1,2,3,4,5);

    return 0;
}
