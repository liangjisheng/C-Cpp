// ConsoleApplication23.cpp: 主项目文件。
// Defining and using a value class type
#include "stdafx.h"

using namespace System;

// Class representing a height
value class Height
{
private:
	// Records the height in feet and inches
	int feet;
	int inches;
public:
	// Create a height from inches value
	Height(int ins)
	{
		feet = ins / 12;
		inches = ins % 12;
	}
	Height(int ft, int ins) : feet(ft), inches(ins) {}

	// Create a string representation of the object
	virtual String^ ToString() override
	{
		return feet + L" feet " + inches + L" inches.";
	}
};

int main(array<System::String ^> ^args)
{
	Height myHeight(Height(6, 3));
	Height^ yourHeight(Height(70));
	Height hisHeight(*yourHeight);

	Console::WriteLine(L"My heigth is {0}", myHeight);
	Console::WriteLine(L"Your height is {0}", yourHeight);
	Console::WriteLine(L"His height is {0}", hisHeight);

	Console::ReadLine();
    return 0;
}
