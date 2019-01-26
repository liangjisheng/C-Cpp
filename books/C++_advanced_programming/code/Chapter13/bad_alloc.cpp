#include <iostream>
#include <new>
using namespace std;

int main()
{
    int num = 5;
    int* ptr = nullptr;
    try{
        ptr = new int[num];
    }catch(const bad_alloc& e){
        cerr << __FILE__ << "(" << __LINE__
        << "): Unable to allocate memory: " << e.what() << endl;
        // Handle memory allocation failure.
        return -1;
    }

    return 0;
}
