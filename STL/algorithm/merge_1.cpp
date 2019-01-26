#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function template to populate(Моід) a container of ints.
// The container must support push_back().
template<typename Container>
void populateContainer(Container& cont)
{
    int num;
    while(true)
    {
        cout << "Enter a number (0 to quit): ";
        cin >> num;
        if(0 == num)
            break;
        cont.push_back(num);
    }
}

int main()
{
    vector<int> vec1, vec2, vecMerged;
    cout << "Enter values for first vector: " << endl;
    populateContainer(vec1);
    cout << "Enter values for second vector: " << endl;
    populateContainer(vec2);

    // sort both container
    sort(vec1.begin(), vec1.end());
    sort(vec2.begin(), vec2.end());

    // Make sure the destination vector is large enough to hold the values
    // from both source vectors.
    vecMerged.resize(vec1.size() + vec2.size());

    merge(vec1.cbegin(), vec1.cend(), vec2.cbegin(), vec2.cend(),
          vecMerged.begin());

    cout << "Merged vector: ";
    for(const auto& i : vecMerged)
        cout << i << ' ';
    cout << endl;

    return 0;
}
