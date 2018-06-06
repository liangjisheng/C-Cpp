// Calculate the value of expression
// 此程序先不处理圆括号，只处理含有数字与+ - * / 的表达式.
// 求此表达式的值,表达式可以看成一项加数或者多项加数的加和减
// 使用term()来求一项的值，然后相加或减，供expr()使用
// 此一项中只包含数字与* /,使用number()求出每一项乘数
// 供term()使用.这次则可以求出不带括号的表达式的值，
// 表达式为中序表达式
#include <iostream>
#include <cstdlib>
#include <cctype>
using std::cout;
using std::cin;
using std::endl;

// Funciton to eliminate spaces from s string
void eatspace(char* str);
// Function to evaluate an arithmetic expression
double expr(char* str);
// Function to get the value of a term
double term(char* str, int& index);
// Function to recognize a number in a string
double number(char* str, int& index);

int main(void)
{
	const int MAX(80);
	char str[MAX];

	cout << endl
		<< "Welcome to your friendly calcualtro."
		<< endl
		<< "Enter an expression,or an empty line to quit."
		<< endl;
	
	for(;;)
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
double number(char* str,int& index)
{
	double value(0.0);

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

// Function to get the value of a term
double term(char* str,int& index)
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