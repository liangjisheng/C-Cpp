#include <iostream>
#include <vector>

using namespace std;

void printVector(const vector<int>& src);

int main()
{
    vector<int> vectorOne = {1,2,3,5};
    vector<int> vectorTwo;

    // forget to add 4. Insert it in the correct place
    vectorOne.insert(vectorOne.cbegin() + 3, 4);
    // add element 6 through 10 to vectorTwo
    for(int i = 6; i <= 10; ++i)
        vectorTwo.push_back(i);

    printVector(vectorOne);
    printVector(vectorTwo);

    vectorOne.insert(vectorOne.cend(),
                     vectorTwo.cbegin(),vectorTwo.cend());
    printVector(vectorOne);

    vectorTwo.clear();
    // Add 10 copies of the value 100
    vectorTwo.insert(vectorTwo.cbegin(),10,100);
    printVector(vectorTwo);

    vectorTwo.pop_back();
    printVector(vectorTwo);

    return 0;
}


void printVector(const vector<int>& src)
{
    cout << endl;
    for(const auto& it : src)
        cout << it << " ";
    cout << endl;
}
