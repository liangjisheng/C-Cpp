// ConsoleApplication17.cpp: 主项目文件。
// Passing a variable number of arguments to a function
#include "stdafx.h"

using namespace System;

double sum(...array<double>^ args)
{
	double sum(0.0);
	for each (double var in args)
		sum += var;
	return sum;
}

int main(array<System::String ^> ^args)
{
	Console::WriteLine(sum(2.0, 4.0, 6.0, 8.0, 10.0, 12.0));
	Console::WriteLine(sum(1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9));

	Console::ReadLine();
    return 0;
}
