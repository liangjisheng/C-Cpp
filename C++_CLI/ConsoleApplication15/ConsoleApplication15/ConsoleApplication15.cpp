// ConsoleApplication15.cpp: 主项目文件。

#include "stdafx.h"

using namespace System;

int main(array<System::String ^> ^args)
{
	// 跟踪引用于标准C++引用功能类似,用%定义
	int value = 10;
	int% trackValue(value);
	Console::WriteLine(L"{0}", value);
	Console::WriteLine(L"{0}", trackValue);
	trackValue = 0;
	Console::WriteLine(L"{0}", value);
	Console::WriteLine(L"{0}", trackValue);

	// 内部指针与标准C++中的指针一样，可以执行算术运算
	array<double>^ data = { 1.5,3.5,6.7,4.2,2.1 };
	interior_ptr<double> pstart(&data[0]);
	interior_ptr<double> pend(&data[data->Length - 1]);
	double sum(0.0);
	while (pstart <= pend)
		sum += *pstart++;

	Console::WriteLine();
	Console::WriteLine(L"Total of data array elements = {0}\n", sum);

	// Just show we can access strings through an interior pointer
	array<String^>^ strings = { L"Land shoy!",
								L"Splice the mainbrace!",
								L"Shiver me timbers!",
								L"Never throw into the wind!"
								};

	for (interior_ptr<String^> pstrings = &strings[0];
		pstrings - &strings[0] < strings->Length; ++pstrings)
		Console::WriteLine(*pstrings);

	Console::ReadLine();
    return 0;
}