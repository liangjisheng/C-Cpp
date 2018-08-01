#include <iostream>
#include <vector>
#include <numeric>
#include <chrono>

using namespace std;
volatile int sink;

int main()
{
    using namespace std::chrono;

    for(auto i = 1ull; i < 1000000000ull; i *= 100)
    {
        auto Start = system_clock::now();
        vector<int> v(i, 42);
        sink = accumulate(v.begin(), v.end(), 0u);
        auto End = system_clock::now();

        duration<double> diff = End - Start;
        cout << "Time to fill and iterate a vector of "
            << i << " ints : " << diff.count() << " s" << endl;
    }

    return 0;
}
