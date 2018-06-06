
// .c文件中value()函数以C链接的方式命名，用C++程序调用时如果不加extern
// 就会出现链接错误，找不到函数在哪里定义的
int value() { return 5; }