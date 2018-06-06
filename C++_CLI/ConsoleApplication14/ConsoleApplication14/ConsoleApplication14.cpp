// ConsoleApplication14.cpp: 主项目文件。
// Using an array of arrays
#include "stdafx.h"

using namespace System;

int main(array<System::String ^> ^args)
{
	array< array<String^>^ >^ grades = gcnew array< array<String^>^ >
	{
		gcnew array<String^>{"Louise", "Jack"},
			gcnew array<String^>{"Bill","Mary","Ben","Joan"},
			gcnew array<String^>{"Jill","Will","Phil"},
			gcnew array<String^>{"Ned","Fred","Ted","Jed","Ed"},
			gcnew array<String^>{"Dan","Ann"}
	};

	wchar_t gradeLetter('A');

	for each (array<String^>^ grade in grades)
	{
		Console::WriteLine(L"Students with Grade {0}:", gradeLetter++);

		for each (String^ student in grade)
			Console::Write(L"{0,12}", student); // Output the current name
		Console::WriteLine();
	}

	Console::WriteLine();

	for (int j = 0; j < grades->Length; j++)
	{
		Console::WriteLine(L"Students with Grade {0}:", gradeLetter++);
		for (int i = 0; i < grades[j]->Length; i++)
			Console::Write(L"{0,12}", grades[j][i]);
		Console::WriteLine();
	}

	array<int>^ values = { 2,456,23,-46,34211,456,5609,112098,
		234,-76504,341,6788,-909121,99,10 };
	String^ formatStr1(L"{0,");	// 1st half of format string
	String^ formatStr2(L"}");	// 2nd half of format string
	String^ number;

	// Find the length of the maximum length value string
	int maxLength(0);
	for each (int value in values)
	{
		number = L"" + value;	// Create string format value
		if (maxLength < number->Length)
			maxLength = number->Length;
	}

	// Create the format string to be used for output
	String^ format(formatStr1 + (maxLength + 1) + formatStr2);

	// Output the values
	Console::WriteLine();
	int numberPerLine(3);
	for (int i = 0; i < values->Length; i++)
	{
		Console::Write(format, values[i]);
		if ((i + 1) % numberPerLine == 0)
			Console::WriteLine();
	}

	// PadLeft(),PadRight()在字符串的左边或右边填充字符
	String^ value(L"3.142");
	String^ leftPadded(value->PadLeft(10));
	String^ rightPadded(value->PadRight(10));
	Console::WriteLine();
	Console::WriteLine(L"{0}", value);
	Console::WriteLine(L"{0}", leftPadded);
	Console::WriteLine(L"{0}", rightPadded);
	
	String^ leftPadded_1(value->PadLeft(10,L'*'));
	String^ rightPadded_1(value->PadRight(10,L'#'));
	Console::WriteLine();
	Console::WriteLine(L"{0}", leftPadded_1);
	Console::WriteLine(L"{0}", rightPadded_1);

	String^ proverb(L"Many hands make light work.");
	String^ newProverb(proverb->Insert(5, L"deck "));
	Console::WriteLine();
	Console::WriteLine(L"{0}", proverb);
	Console::WriteLine(proverb->ToUpper());
	Console::WriteLine(L"{0}", newProverb);
	Console::WriteLine(proverb->Replace(L' ', L'*'));
	Console::WriteLine(proverb->Replace(L"Many hands", L"Pressing switch"));

	Console::WriteLine();
	String^ him(L"Jacko");
	String^ her(L"Jillo");
	int result(String::Compare(him, her));
	if (result < 0)
		Console::WriteLine(L"{0} is less than {1}.", him, her);
	else if (result > 0)
		Console::WriteLine(L"{0} is great than {1}.", him, her);
	else
		Console::WriteLine(L"{0} is equal to {1}.", him, her);

	// 测试某个字符串是否已给定的子字符串开始或结束.
	// StartsWith(),EndsWith()
	Console::WriteLine();
	String^ sentence(L"Hide, the cow's outside.");
	Console::WriteLine(L"{0}", sentence);
	if (sentence->StartsWith(L"Hide"))
		Console::WriteLine(L"The sentence starts with 'Hide'.");
	Console::WriteLine(L"The sentence does{0} end with 'outside'.",
		sentence->EndsWith(L"outside") ? L"" : L" not");

	// IndexOf();搜索给定字符或字符串在字符串中第一次出现的位置
	int ePosition(sentence->IndexOf(L'e'));
	int thePosition(sentence->IndexOf(L"the"));
	Console::WriteLine(L"Index of e in sentence is {0}", ePosition);
	Console::WriteLine(L"Index of the in sentence is {0}", thePosition);

	String^ words(L"wool wool sheep sheep wool wool wool");
	String^ word(L"wool");
	int index(0);
	int count(0);
	while ((index = words->IndexOf(word, index)) >= 0)
	{
		index += word->Length;
		++count;
	}
	Console::WriteLine();
	Console::WriteLine(L"'{0}' was found {1} times in:\n{2}",
		word, count, words);

	index=(words->Length - 1);
	count = 0;
	while (index >= 0 && (index = words->LastIndexOf(word, index)) >= 0)
	{
		--index;
		++count;
	}
	Console::WriteLine(L"'{0}' was found {1} times in:\n{2}",
		word, count, words);

	Console::ReadLine();
    return 0;
}