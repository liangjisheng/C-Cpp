// ConsoleApplication12.cpp: 主项目文件。

#include "stdafx.h"

using namespace System;

int main(array<System::String ^> ^args)
{
	array<int>^ samples = { 27,3,54,11,18,2,16 };
	Array::Sort(samples);	// Sort the array elements

	for each (int var in samples)
		Console::Write(L"{0,8}", var);
	Console::WriteLine();

	array<int>^ samples_1 = { 27,3,54,11,18,2,16 };
	Array::Sort(samples_1, 2, 3); // 对索引2之后的3个元素排序
	for each (int var in samples_1)
		Console::Write(L"{0,8}", var);
	Console::WriteLine();

	Console::WriteLine();
	// Sorting an array of keys(the names) and an array of objects(the weigths)
	array<String^>^ names = { "Jill","Ted","Mary","Eve","Bill","Al" };
	array<int>^ weithts = { 103,168,128,115,180,176 };

	// Sort the arrays,对names进行排序，同时也对对应的weights进行排序
	Array::Sort(names, weithts);	
	for each (String^ var in names)
		Console::Write(L"{0,10}", var);
	Console::WriteLine();

	for each (int var in weithts)
		Console::Write(L"{0,10}", var);
	Console::WriteLine();

	Console::WriteLine();
	array<int>^ values = { 23,45,68,94,123,127,150,203,299 };
	int toBoFound(127);
	// 使用二分搜索查找以排好序的数组
	int position = Array::BinarySearch(values, toBoFound);
	if (position < 0)
		Console::WriteLine(L"{0} was not found.", toBoFound);
	else
		Console::WriteLine(L"{0} was found at index position {1}.",
			toBoFound, position);

	Console::ReadLine();
    return 0;
}