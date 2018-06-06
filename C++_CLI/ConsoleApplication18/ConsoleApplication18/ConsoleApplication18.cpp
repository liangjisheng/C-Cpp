// ConsoleApplication18.cpp: 主项目文件。
// Receiving multiple command line arguments
#include "stdafx.h"

using namespace System;

int main(array<System::String ^> ^args)
{
	Console::WriteLine(L"There were {0} command line arguments.",
		args->Length);
	Console::WriteLine(L"Command line arguments received are:");
	int i = 1;
	for each (String^ str in args)
		Console::WriteLine(L"Argument {0}: {1}", i++, str);

	Console::ReadLine();
    return 0;
}
