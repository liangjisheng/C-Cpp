
// C++中引用C函数

// extern "C"表示编译生成的内部符号名使用C约定，否则会出现链接错误
extern "C"
{
void mytest();
}

int main()
{
	mytest();
	return 0;
}