
#include <iostream>
#include <string>
#include "ignore.hpp"

int main()
{
	// ignore the rest of the line
	std::cin >> ignoreLine;
	std::string str;
	std::cin >> str;
	std::cout << str << std::endl;

	// 如果想忽略若干行，就多调用几次
	std::cin >> ignoreLine >> ignoreLine >> ignoreLine;
	std::cin >> str;
	std::cout << str <<std::endl;

	system("pause");
	return 0;
}
