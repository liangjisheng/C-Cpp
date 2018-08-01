#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    // The list of elements to be searched
    vector<int> vec = {5, 6, 9, 8, 8, 3 };

    // Find the first element that does not satisfy the given lambda expression
    auto it = find_if(vec.begin(), vec.end(),
                      [](int i) { return i < 8; });
    if(it != vec.end())
        cout << "First element not < 8 is :" << *it << endl;
    else
        cout << "There is not number less than 8." << endl;

    // Find the min and max elements in the vector
    auto res = minmax_element(vec.begin(), vec.end());
    cout << "min is :" << *(res.first) << " and max is :"
        << *(res.second) << endl;

    // Find the min and max elements in the vector
    it = min_element(vec.begin(), vec.end());
    auto it2 = max_element(vec.begin(), vec.end());
    cout << "min is :" << *it << " and max is :" << *it2 << endl;

    // Find the first pair of matching consecutive elements,发现两个连续相等的元素
    it = adjacent_find(vec.begin(), vec.end());
    if(it != vec.end())
        cout << "Found two consecutive equal elements with value " << *it
            << endl;

    // Find the first of two values
    vector<int> targets = {8, 9 };
    it = find_first_of(vec.begin(), vec.end(),
                       targets.begin(), targets.end());
    if(it != vec.end())
        cout << "Found one of 8 or 9 :" << *it << endl;

    // Find the first subsequence
    vector<int> sub = {8, 3};
    it = search(vec.begin(), vec.end(),
                sub.cbegin(), sub.cend());
    if(it != vec.end()){
        cout << "Found subsequence {8, 3}" << endl;
        cout << *it << endl;
    }
    else
        cout << "Unable to find subsequence {8, 3}." << endl;

    // Find the last subsequence (which is the same as the first in this example)
    it2 = find_end(vec.begin(), vec.end(),
                   sub.cbegin(), sub.cend());
    if(it != it2){
        cout << "Error: search and find_end found different subsequence "
            << "even though there is only one match." << endl;
    }
    cout << *it2 << endl;

    // Find the first subsequence of two consecutive 8s
    it = search_n(vec.begin(), vec.end(),2, 8);
    if(it != vec.end()){
        cout << "Found two consecutive 8s" << endl;
        cout << *it << endl;
    }
    else{
        cout << "Unable to find two consecutive 8s" << endl;
    }

    return 0;
}
