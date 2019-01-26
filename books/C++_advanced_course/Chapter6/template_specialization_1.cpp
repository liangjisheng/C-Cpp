
// 模板特化不同于模板实例化，他指明了函数模板在特殊情况下(模板参数为某种特定
// 类型)下的实现版本。


#include <iostream>
#include <string.h>

using std::cout;
using std::endl;

template<typename T>
T myMax(T t1, T t2) { return t1 > t2 ? t1 : t2; }

typedef const char* PCC;

// const char*显示特化，覆盖了来自通用模板的定义的实例
//template<> 
//PCC myMax<PCC>(PCC s1, PCC s2) { return (strcmp(s1, s2) > 0) ? s1 : s2; }


// 参数类型为const char*的重载函数,代替函数模板的特化
PCC myMax(PCC s1, PCC s2) { return (strcmp(s1, s2) > 0) ? s1 : s2; }


// 普通重载函数与使用模板特化之间的不同：
// 使用普通重载函数，不管是否发生实际的函数调用，都会在目标文件中生成该函数的
// 二进制代码。而如果使用模板的特化版本，除非发生函数调用，否则不会在目标文件
// 中包含特化模板函数的二进制代码，符合函数模板的惰性实例化准则
// 使用普通重载函数，在分离编译模式下，应该在各个源文件中包含重载函数的声明
// 否则在某些源文件中就会使用模板实例化，而不是重载函数


int main()
{
	// myMax<int>(int, int);
	int i = myMax(10, 5);

	// 调用显示特化:const char* myMax<const char*>(const char*, const char*)
	const char *p = myMax("very", "good");

	cout << i << endl;
	cout << p << endl;		// very
	cout << *p << endl;		// v

	system("pause");
	return 0;
}

