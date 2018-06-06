#include <stdio.h>
#include <stdlib.h>
#include <iso646.h>

// iso646.h中定义了一下的宏，and和or并不是真正新加的关键字
//#define and         &&
//#define and_eq      &=
//#define bitand      &
//#define bitor       |
//#define compl       ~
//#define not         !
//#define not_eq      !=
//#define or          ||
//#define or_eq       |=
//#define xor         ^
//#define xor_eq      ^=


int main()
{
    int i = 5, j = 6, k = 7;
    if(i < j and j < k)
        printf("i < j and j < k\n");
    if(i < j or j < k)
        printf("i < j or j < k\n");

    // printf("Hello world!\n");
    getchar();
    return 0;
}
