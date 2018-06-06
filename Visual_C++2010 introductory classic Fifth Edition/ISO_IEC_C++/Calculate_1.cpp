// 扩展计算器，增加圆括号处理的功能
// 可以将圆括号内的表示式看做是term的组成部分,
// 修改number()来求出圆括号之间表达式的值
// 可以使用expr(),使用递归简化该问题，
// 递归函数将自动处理嵌套圆括号.使用计数器处理多个圆括号的问题
#include <iostream>
#include <cstdlib>
#include <cctype>
#include <cstring>
using std::cout;
using std::cin;
using std::endl;

const int MAX(80);

// Funciton to eliminate spaces from s string
void eatspace(char* str);
// Function to evaluate an arithmetic expression
double expr(char* str);
// Function to get the value of a term
double term(char* str, int& index);
// Function to recognize a number in a string
double number(char* str, int& index);
// Function to extract s substring between parentheses
char* extract(char* str, int& index);

int main(void)
{
	char str[MAX];

	cout << endl
		<< "Welcome to your friendly calcualtro."
		<< endl
		<< "Enter an expression,or an empty line to quit."
		<< endl;

	for (;;)
	{
		cin.getline(str, MAX);
		eatspace(str);

		if (!str[0])
			return 0;

		cout << "\t= " << expr(str)
			<< endl << endl;
	}

	system("pause");
	return 0;
}

// Funciton to eliminate spaces from s string
void eatspace(char* str)
{
	int i(0);
	int j(0);

	while ((*(str + i) = *(str + j++)) != '\0')
		if (*(str + i) != ' ')
			i++;
}

// Function to recognize a number in a string
double number(char* str, int& index)
{
	double value(0.0);

	if (*(str + index) == '(')
	{
		char* psubstr(nullptr);
		psubstr = extract(str, ++index); // Extract substring in brackets
		value = expr(psubstr);
		delete[]psubstr;
		return value;
	}

	// There must be at least one digit
	if (!isdigit(*(str + index)))
	{
		// There 's no digits so input is junk...
		cout << endl
			<< "Arrrgh!*#!! There's an error."
			<< endl;
		exit(1);
	}

	while (isdigit(*(str + index)))
		value = 10 * value + (*(str + index++) - '0');

	// Not a digit when we get to here so check for decimal point
	if (*(str + index) != '.')
		return value;	// if not ,return value

	double factor(1.0);	// Factor for decimal places
	while (isdigit(*(str + (++index))))
	{
		factor *= 0.1;
		// Add decimal place
		value = value + (*(str + index) - '0') * factor;
	}
	return value;
}

// Function to extract s substring between parentheses
char * extract(char * str, int & index)
{
	char buffer[MAX];	// Temporary space for substring
	char* pstr(nullptr);// Pointer to new string for return 
	int numL(0);		// Count of left parentheses found
	int bufindex(index);// Save starting value for index

	do
	{
		buffer[index - bufindex] = *(str + index);
		switch (buffer[index - bufindex])
		{
		case ')':
			if (0 == numL)
			{
				buffer[index - bufindex] = '\0';	// Replace ')' with '\0'
				++index;
				pstr = new char[index - bufindex];
				if (!pstr)
				{
					cout << "Memory allocation failed,"
						<< " program terminated.";
					exit(1);
				}
				strcpy_s(pstr, index - bufindex, buffer);
				return pstr;
			}
			else
				numL--;	// Reduce count of '(' to be matched
			break;
		case '(':
			numL++;
			break;
		}	// end of swtich
	} while (*(str + index++) != '\0');	// Loop - don't overrun end of string

	cout << "Ran off the end of the expression,must be bad input."
		<< endl;
	exit(1);
}

// Function to get the value of a term
double term(char* str, int& index)
{
	double value(0.0);
	value = number(str, index);	// Get the first number in the term

								// Loop as long as we have a good operator
	while (true)
	{
		if (*(str + index) == '*')
			value *= number(str, ++index);
		else if (*(str + index) == '/')
			value /= number(str, ++index);
		else
			break;
	}
	return value;
}

// Function to evaluate an arithmetic expression
double expr(char* str)
{
	double value(0.0);	// Store result here
	int index(0);	// Keeps track of current character position

	value = term(str, index);	// Get first term

	for (;;)
	{
		switch (*(str + index++))
		{
		case '\0':
			return value;
		case '+':
			value += term(str, index);
			break;
		case '-':
			value -= term(str, index);
			break;
		default:
			cout << endl
				<< "Arrrgh!*#!! There's an error"
				<< endl;
			exit(1);
		}
	}
}