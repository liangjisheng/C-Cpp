#include <iostream>

using namespace std;

bool is_r_value(int &&) { return true; }
bool is_r_value(const int &)
{
    return false;
}

int main()
{
    int i = 0;
    cout << is_r_value(i) << endl;
    cout << is_r_value(std::move(i)) << endl;

    return 0;
}
