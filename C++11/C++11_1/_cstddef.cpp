
// NULL通常用来表明一个不指向任何对象的指针，其实就是0，
// C中NULL通常定义为(void*)0,

// cstddef中的定义项
// NULL表示未定值或者无值
// size_t一种无正负号类型，用来表示大小
// ptrdiff_t一种带有正负号的类型，用来表示指针之间的距离
// offsetof表示一个成员在struct或union中的偏移量

// cstdlib中的定义项
// exit(int status)退出程序并清理static对象,将所有缓冲区(buffer)
// 清空(flushes)，关闭所有IO通道,然后终止程序(之前会调用经由atexit()
// 注册的函数)，如果atexit()注册的函数抛出异常，就会调用terminate()
// EXIT_SUCCESS程序正常结束
// EXIT_FAILURE程序不正常结束
// abort()会立即终止函数，不做任何清理工作
// atexit(void (*function)())退出exit程序时调用某些函数

// exit()和abort()都不会销毁局部对象，因为堆栈辗转开展动作(stack unwinding)
// 不会被执行起来，为确保所有的句柄对象的析构函数获得调用，应该运用异常
// 或正常机制返回，然后在有main()离开