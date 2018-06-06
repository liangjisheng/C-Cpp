// ConsoleApplication11.cpp: 主项目文件。

#include "stdafx.h"

using namespace System;

int main(array<System::String ^> ^args)
{
	// 为引用类型创建跟踪句柄 类似于指针，里面含有内部指针
	String^ saying(L"I used to think I was indecisive but now I'm not so sure");
	// 为值类型创建跟踪句柄
	int^ value = 99;
	// 不需显示的解除引用符号，编译器会处理
	int result(2 * (*value) + 15);

	array<int>^ data;
	data = gcnew array<int>(100);
	for (int i = 0; i < 100; i++) {
		data[i] = 2 * (i + 1);
		Console::Write("{0,5}", data[i]);
		if ((i + 1) % 5 == 0)
			Console::WriteLine();
	}

	Console::WriteLine();
	// 使用数组的Length属性
	for (int i = 0; i < 100; i++) {
		data[i] = 3 * (i + 1);
		Console::Write("{0,5}", data[i]);
		if ((i + 1) % 5 == 0)
			Console::WriteLine();
	}

	Console::WriteLine();
	// for each
	array<int>^ values = { 3,5,6,8,6 };
	for each (int item in values)
	{
		item = 2 * item + 1;
		Console::Write("{0,5}", item);
	}
	Console::WriteLine();

	Console::WriteLine();
	array<String^>^ names;
	names = gcnew array<String^>{"Jack", "Jane", "Joe", "Jessica", "Jim", "Joanna"};
	for each (String^ var in names)
	{
		Console::Write("{0,10}", var);
	}
	Console::WriteLine();

	array<double>^ samples = gcnew array<double>(50);

	// Generate random element values
	Random^ generator = gcnew Random;
	for (int i = 0; i < samples->Length; i++)
		samples[i] = 100.0 * generator->NextDouble();

	// Output the samples
	Console::WriteLine();
	Console::WriteLine(L"The array contains the following values:");
	for(int i=0;i<samples->Length;i++)
	{
		Console::Write(L"{0,10:F2}", samples[i]);
		if ((i + 1) % 5 == 0)
			Console::WriteLine();
	}

	// Find the maximum value
	double max(0);
	for each (double var in samples)
		if (max < var) max = var;
	Console::WriteLine(L"The maximum value in the array is {0:F2}", max);
	
	Console::ReadLine();
    return 0;
}