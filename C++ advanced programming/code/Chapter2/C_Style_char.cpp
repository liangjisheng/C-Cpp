#include <iostream>

using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    // 上面的代码中，"Hello world"是一个字符串字面量(string literal
    // 因为这个字符串已值的形式写出，而不是一个变量，与
    // 字符串字面量关联的真正内存在内存的只读部分中。通过
    // 这种方式，编译器可以重用等价的字符串字面量的引用，
    // 来优化内存的使用。也就是说，即使一个程序使用了500次
    // "Hello,world"字符串字面量，编译器也只是内存中创建
    // 一个"Hello,world"实例。这种技术称为字面量池(literal pooling)
    // C++标准正式指出：字符串字面量的类型为n个const char
    // 的数组，

    char* ptr = "hello";
    // ptr[0] = 'a';        // Undefined behavior

    // 一种更安全的编码方法，使用指向const字符的指针
    const char* cPtr = "hello";
    // cPtr[0] = 'a';       // Error! Attempts to write to read-only memory

    // 可以创建一个字符数组,编译器不会讲字面量放在只读的内存中
    char arr[] = "hello";
    arr[0] = 'a';

    return 0;
}
