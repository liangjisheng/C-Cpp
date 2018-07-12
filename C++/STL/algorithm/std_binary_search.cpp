
#include <vector>
#include <numeric>
#include <iostream>
#include <functional>
#include <algorithm>
#include <iterator>

int main()
{
	std::vector<int> coll{1, 2, 3, 4, 5, 6, 7, 8, 9};
	std::cout << std::boolalpha << "5 present? "
		<< std::binary_search(coll.cbegin(), coll.cend(), 5) << std::endl;
	std::cout << std::boolalpha << "42 present? "
		<< std::binary_search(coll.cbegin(), coll.cend(), 42) << std::endl;
	std::cin.get();
}