// Calculate.cpp: 主项目文件。
// A CLR calculator supporting parentheses
#include "stdafx.h"
#include <cstdlib>

using namespace System;
String^ eatspace(String^ str);
double expr(String^ str);
double term(String^ str, int^ index);
double number(String^ str, int^ index);
String^ extract(String^ str, int^ index);

int main(array<System::String ^> ^args)
{
	String^ buffer;

	Console::WriteLine(L"Welcome to your friendly calculte");
	Console::WriteLine(L"Enter an expression,or an empty line to quit.");

	for (;;)
	{
		buffer = eatspace(Console::ReadLine());

		if (String::IsNullOrEmpty(buffer))
			return 0;
		// Output value of expression
		Console::WriteLine(L" = {0}\n\n", expr(buffer));
	}

	Console::ReadLine();
    return 0;
}

String^ eatspace(String^ str)
{
	return str->Replace(L" ", L"");
}

double expr(String^ str)
{
	int^ index(0);
	double value(term(str, index));

	while (*index < str->Length)
	{
		switch (str[*index])
		{
		case '+':
			++(*index);
			value += term(str, index);
			break;
		case '-':
			++(*index);
			value -= term(str, index);
			break;
		default:
			Console::WriteLine(L"Arrrgh!*#!! There's an error.\n");
			exit(1);
		}
	}
	return value;
}

double term(String^ str, int^ index)
{
	double value(number(str, index));

	// Loop as long as we have characters and a good operator
	while (*index < str->Length)
	{
		if (L'*' == str[*index])
		{
			++(*index);
			value *= number(str, index);
		}
		else if (L'/' == str[*index])
		{
			++(*index);
			value /= number(str, index);
		}
		else
			break;
	}
	return value;
}

double number(String^ str, int^ index)
{
	double value(0.0);

	// Check for expression between praentheses
	if (L'(' == str[*index])
	{
		++(*index);
		String^ substr = extract(str, index);
		return expr(substr);
	}

	// There must be at least one digit...
	if (!Char::IsDigit(str, *index))
	{
		Console::WriteLine(L"Arrrgh!*#!! There's an error.\n");
		exit(1);
	}

	// Loop accumulating leading digits
	while ((*index < str->Length) && Char::IsDigit(str, *index))
	{
		value = 10.0*value + Char::GetNumericValue(str[(*index)]);
		++(*index);
	}

	// Not a digit when we get to here
	if ((*index == str->Length) || str[*index] != '.')
		return value;

	double factor(1.0);		// Factor for decimal places
	++(*index);

	// Loop as long as we have digits
	while ((*index < str->Length) && Char::IsDigit(str, *index))
	{
		factor *= 0.1;
		value = value + Char::GetNumericValue(str[*index])*factor;
		++(*index);
	}
	return value;
}

String^ extract(String^ str, int^ index)
{
	int numL(0);	// Count of left praentheses found
	int bufindex(*index);

	while (*index < str->Length)
	{
		switch (str[*index])
		{
		case ')':
			if (0 == numL)
				return str->Substring(bufindex, (*index)++ - bufindex);
			else
				numL--;
			break;
		case '(':
			numL++;
			break;
		}
		++(*index);
	}

	Console::WriteLine(L"Ran off the end of the expression,must be bad input.");
	exit(1);
}