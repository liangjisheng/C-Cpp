#include <iostream>
#include <vector>
#include <list>

using namespace std;

// Function template to populate(Ìî³ä) a container of ints.
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
    vector<int> myVec;
    list<int> myList;
    cout << "Populate the vector: " << endl;
    populateContainer(myVec);
    cout << "Populate the list: " << endl;
    populateContainer(myList);

    // compare the tow containers
    if(myVec.size() == myList.size() &&
       equal(myVec.cbegin(),myVec.cend(),myList.cbegin()))
    {
        cout << "The two containers have equal elements." << endl;
    }
    else
    {
        if(myList.size() < myVec.size()){
            cout << "Sorry, the list is not log enough." << endl;
        }else{
            // if the containers were not equal, find out why not
            auto miss = mismatch(myVec.cbegin(), myVec.cend(), myList.cbegin());
            cout << "The following initial elements are the same in "
                << "the vector and the list: " << endl;
            for(auto i = myVec.cbegin(); i != miss.first; ++i)
                cout << *i << '\t';
            cout << endl;
        }
    }

    // Now order them  lexicographically(×Öµä)
    if(lexicographical_compare(myVec.cbegin(), myVec.cend(),
                               myList.cbegin(),myList.cend())){
        cout << "The vector is lexicographically first." << endl;
    }
    else
        cout << "The list is lexicographically first." << endl;

    return 0;
}
