
// 调用op()产生新值，并赋值给区间[beg, end)
// void generate(ForwardIterator beg, ForwardIterator end, Func op);

// 调用op()产生新值，并赋值给以beg起始的区间内的前num个元素
// void generate_n(OutputIterator beg, Size num, Func op);

#include "..\..\algostuff.hpp"
#include <cstdlib>
#include <ctime>
using namespace std;


int main()
{
	list<int> coll;

	srand(unsigned int(time(NULL)));
	// insert five random numbers
	generate_n(back_inserter(coll), 5, rand);
	
	PRINT_ELEMENTS(coll);

	// overwrite with five new random numbers
	generate(coll.begin(), coll.end(), rand);
	PRINT_ELEMENTS(coll);

	system("pause");
	return 0;
}