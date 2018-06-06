
// 常量分为两种：文字常量和常变量
// 文字常量又称为符号常量或者字面常量，在编译之后写在代码区，
// 是不可寻址的。而常变量同其它变量一样被分配空间，是可以寻址的
// 利用define定义的常量也属于文字常量

// 有些特殊的标识符，同时满足这样两个条件：不可寻址，值不可变，
// 所以可以将他们视为文字常量，静态数组名、枚举常量、全局(静态变量)首地址
// 由于运行是常变量并不是放在只读内存中，而是和一般变量一样放在
// 数据区，所以在运行时如果能获得常变量的地址，一样可以通过特殊的
// 途径对他们进行修改

#include <stdio.h>

void ShowValue(const int i)
{
    printf("%d\n", i);
}

int main()
{
    const int j = 5;
    int *ptr = NULL;
    void *p = (void*)&j;
    ptr = (int*)p;
    (*ptr)++;
    // 若直接打印j，可能输出的结果是5，这并不是说常量j的值没有
    // 变化，而是编译器在代码优化的过程找那个已经将j替换成了
    // 文字常量5的缘故
    //printf("%d\n", j);
    ShowValue(j);

    //system("pause");
    return 0;
}
