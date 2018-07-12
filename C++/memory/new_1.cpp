
// heap corruption detected:after normal block(#xxx) at 0x xxxxxxxx
// crt detected that the application wrote to menory after end of heap buffer
// 这是典型的内存溢出错误,常在内存的delete处发生,
// 而且一般在debug版本中可能出现,release版本中可能并不报错.
// 出现这个错误的原因一般都是操作new申请的内存溢出,
// 因为在c++中,如果用new分配一段内存,操作的时候改变了该部分的大小,在delete时就会出错.

#include <iostream>
#include <string.h>

using namespace std;

int main()
{
	char *p = new char[5];
	memset(p, '\0', 5);
	strcpy(p, "aaaaa");

	// 这段代码就会出错,因为申请了一个size为5的内存,
	// 但是strcpy过去了一个size为6的字符串,因此破坏了这个指针,
	// 运行debug版本的时候就会出现先前的错误,但是在release版本中,
	// 溢出一个字节的内存很有可能是没有错误的,
	// 然后潜在的隐患是肯定存在的,因此,
	// 我们在debug遇到这样的错误时候一定要仔细检查对new出的指针的操作.
	delete [] p;

	system("pause");
	return 0;
}