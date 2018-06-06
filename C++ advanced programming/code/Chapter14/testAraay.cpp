#include <iostream>
#include "Array.h"
using namespace std;

void printArray(const Array<int>& arr,size_t Size);

int main()
{
    Array<int> myArray;
    for(size_t i = 0; i < 10; ++i){
        //myArray.setElementAt(i,100);

        // Calls the non-const operator[] because myArray is a non-const object
        myArray[i] = 100;
    }

    printArray(myArray,10);

    //for(size_t i = 0; i < 10; ++i){
    //    cout << myArray.getElementAt(i) << " ";
    //}
    //cout << endl;

    return 0;
}

void printArray(const Array<int>& arr,size_t Size)
{
    for(size_t i = 0; i < Size; ++i){
        // Calls the const operetor[] because arr is a const object
        cout << arr[i] << endl;
    }
    cout << endl;
}
