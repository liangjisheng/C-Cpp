// ConsoleApplication13.cpp: 主项目文件。
// Searching an array
#include "stdafx.h"

using namespace System;

int main(array<System::String ^> ^args)
{
	array<String^>^ names = { "Jill","Ted","Mray","Eve","Bill",
							"Al","Ned","Zoe","Dan","Jean" };
	array<int>^ weights = { 103,168,128,115,180,
							176,209,98,190,130 };
	array<String^>^ toBeFound = { "Bill","Eve","Al","Fred" };
	Array::Sort(names, weights);

	int result(0);
	for each (String^ var in toBeFound)
	{
		result = Array::BinarySearch(names, var);
		if (result < 0)
			Console::WriteLine(L"{0} was not found.", var);
		else
			Console::WriteLine(L"{0} weighs {1} lbs.",
				var, weights[result]);
	}

	// 多维数组
	Console::WriteLine();
	int nrows(4);
	int ncols(5);
	array<int, 2>^ values = gcnew array<int, 2>(nrows, ncols);

	for (int i = 0; i < nrows; i++) {
		for (int j = 0; j < ncols; j++){
			values[i,j] = (i + 1)*(j + 1);
			Console::Write(L"{0,5}", values[i,j]);
		}
		Console::WriteLine();
	}

	// Using a tow-dimensional array
	const int SIZE(12);
	array <int,2>^ products(gcnew array<int, 2>(SIZE, SIZE));

	for (int i = 0; i < SIZE; i++)
		for (int j = 0; j < SIZE; j++)
			products[i, j] = (i + 1)*(j + 1);

	Console::WriteLine(L"Here is the {0} times table:", SIZE);

	// Write horizontal divider line
	for (int i = 0; i <= SIZE; i++)
		Console::Write(L"______");
	Console::WriteLine();

	// Write top line of table
	Console::Write(L"     |");
	for (int i = 1; i <= SIZE; i++)
		Console::Write(L"{0,3}  |", i);
	Console::WriteLine();

	// Write horizontal divider line with verticals
	for (int i = 0; i <= SIZE; i++)
		Console::Write(L"_____|");
	Console::WriteLine();

	// Write remaining lines
	for (int i = 0; i < SIZE; i++)
	{
		Console::Write(L"{0,3}  |", i + 1);
		for (int j = 0; j < SIZE; j++)
			Console::Write(L"{0,3}  |", products[i, j]);
		Console::WriteLine();
	}

	// Write horizontal divider line
	for (int i = 0; i <= SIZE; i++)
		Console::Write(L"_____|");
	Console::WriteLine();

	Console::ReadLine();
    return 0;
}