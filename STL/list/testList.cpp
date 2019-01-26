#include <iostream>
#include <list>
#include <string>
using namespace std;

int main()
{
    // Store the a words in the main dictionary
    list<string> dictionary {"aardvark","ambulance"};
    // Store the b words
    list<string> bWords{ "bathos","balderdash"};
    // Add the c Words to the main dictionary
    dictionary.push_back("canticle");
    dictionary.push_back("consumerism");

    // splice the b words into the main dictionary
    if(bWords.size() > 0){
        auto iterLastB = --(bWords.end());
        auto it = dictionary.cbegin();
        for(; it != dictionary.cend(); ++it){
            if(*it > *iterLastB)
                break;
        }
        // Add in the bWords.This action removes the elements from bWords
        dictionary.splice(it,bWords);
    }

    // print
    for(const auto& word : dictionary){
        cout << word << endl;
    }

    return 0;
}
