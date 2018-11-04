#include <iostream>
#include <iterator>
#include <algorithm>

using namespace std;

void test_1()
{
    std::ostream_iterator<int> i1(std::cout, ", ");
    std::fill_n(i1, 5, -1);
    std::ostream_iterator<double> i2(std::cout);
    *i2++ = 3.14;
}


int main()
{
    test_1();

    return 0;
}
