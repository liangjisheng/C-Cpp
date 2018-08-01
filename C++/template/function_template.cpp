#include <iostream>
#include <cstring>
using namespace std;

static const size_t NOT_FOUND = (size_t)(-1);
template <typename T>
size_t Find(T& value,T* arr,size_t len){
    for(size_t i=0;i<len;++i){
        if(arr[i] == value)
            return i;
    }
    return NOT_FOUND;
}

// 函数模板特化
template<>
size_t Find<const char*>(const char*& value,const char** arr,size_t len)
{
    cout << "Specialization" << endl;
    for(size_t i = 0;i < len; i++) {
        if(strcmp(arr[i],value) == 0)
            return i;
    }
    return NOT_FOUND;
}

int main()
{
    int x = 3;
    int intArr[] = {1,2,3,4};
    size_t sizeIntArr = sizeof(intArr) / sizeof(int);
    size_t res;
    res = Find(x,intArr,sizeIntArr);    // calls Find<int> by deduction
    res = Find<int>(x,intArr,sizeIntArr);   // calls Find<int> explicitly
    if(res != NOT_FOUND)
        cout << res << endl;
    else
        cout << "Not found" << endl;

    double d1 = 5.6;
    double dArr[] = {1.2,3.4,5.7,7.5};
    size_t sizeDoubleArr = sizeof(dArr) / sizeof(double);
    res = Find(d1,dArr,sizeDoubleArr);
    res = Find<double>(d1,dArr,sizeDoubleArr);
    if(res != NOT_FOUND)
        cout << res << endl;
    else
        cout << "Not found" << endl;

    const char* word = "two";
    const char* arr[] = { "one","two","three","four"};
    size_t sizeArr = sizeof(arr) / sizeof(arr[0]);
    res = Find<const char*>(word,arr,sizeArr);
    res = Find(word,arr,sizeArr);
    if(res != NOT_FOUND)
        cout << res << endl;
    else
        cout << "Not found" << endl;

    return 0;
}
