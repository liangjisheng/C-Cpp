endl是一个不带参数操纵算子，它只是一个函数，声明如下：

ostream& endl(ostream);

在编译器里有一个能被自己的函数地址作为本身的参数的函数，它被

成为应用算子。是在IOSTREAM.H中预定义的。

endl 产生一个换行，并刷新这个流。而如下建立的操纵算子

只产生一个环形，而不刷新这个流

//: NL.CPP--Create a manipulator

#include"iostream.h"

ostream& nl(ostream& os)
{return os<<'\n';}

int main(int argc,char* argv[])
{
	cout<<"newlines"<<nl<<"between"<<nl
		<<"each"<<nl<<"word"<<nl;
	return 0;
}