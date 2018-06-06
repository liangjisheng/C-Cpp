#ifndef ROUNDROBIN_H_INCLUDED
#define ROUNDROBIN_H_INCLUDED

// 时间片轮转调度类，用于任何类型的资源，支持添加和删除资源
// 还支持循环遍历资源
#include <vector>
#include <stdexcept>
// Class template RoundRobin
// Provide simple round-robin semantics fro a list of elements
template<typename T>
class RoundRobin
{
public:
    // Client can give a hint as to the number of excepted elements for
    // increased efficiency
    RoundRobin(size_t numExcepted = 0);
    virtual ~RoundRobin();
    RoundRobin(const RoundRobin& src);
    RoundRobin& operator=(const RoundRobin& rhs);

    // Appends elem to the end of the list. May be called
    // between calls to getNext()
    void Add(const T& elem);
    // Remove
    void Remove(const T& elem);
    // Return the next element in the list,starting with the first,
    // and cycling back to the first when the end of the list is
    // reached,
    T& getNext();
private:
    std::vector<T> mElems;
    typename std::vector<T>::iterator mCurElem;
};


template<typename T>
RoundRobin<T>::RoundRobin(size_t numExcepted)
{
    // If the client give a guideline,reserve that much space
    mElems.reserve(numExcepted);
    // Initialize mCurElem even thought it isn't used until
    // there is at least one element
    mCurElem = mElems.end();
}

template<typename T>
RoundRobin<T>::~RoundRobin()
{
    // nothing to do here -- the vector will delete all the elements
}

template<typename T>
RoundRobin<T>::RoundRobin(const RoundRobin& src)
{
    mElems.clear();
    for(auto it = src.mElems.begin(); it != src.mElems.end(); ++it)
        mElems.push_back(*it);

    int pos = src.mCurElem - src.mElems.begin();
    mCurElem = mElems.begin() + pos;
}

template<typename T>
RoundRobin<T>& RoundRobin<T>::operator=(const RoundRobin& rhs)
{
    if(rhs == *this)
        return *this;

    mElems.clear();
    for(auto it = rhs.mElems.begin(); it != rhs.mElems.end(); ++it)
        mElems.push_back(*it);

    int pos = rhs.mCurElem - rhs.mElems.begin();
    mCurElem = mElems.begin() + pos;
    return *this;
}

template<typename T>
void RoundRobin<T>::Add(const T& elem)
{
    int pos = (mCurElem == mElems.end()) ? -1 : (mCurElem - mElems.begin());
    mElems.push_back(elem);
    mCurElem = (pos == -1 ? mElems.end() : mElems.begin() + pos);
}

template<typename T>
void RoundRobin<T>::Remove(const T& elem)
{
    for(auto it = mElems.begin(); it != mElems.end(); ++it)
    {
        if(*it == elem) {
            int newpos;
            if(mCurElem <= it)
                newpos = mCurElem - mElems.begin();
            else
                newpos = mCurElem - mElems.begin() - 1;

            mElems.erase(it);
            // Now reset our iterator to make sure it is valid
            mCurElem = mElems.begin() + newpos;
        }
    }
}

template<typename T>
T& RoundRobin<T>::getNext()
{
    // First,make sure there are any elements
    if(mElems.empty()){
        throw std::out_of_range("No elements in the list");
    }

    if(mCurElem == mElems.end()){
        mCurElem = mElems.begin();
    }
    else{
        ++mCurElem;
        if(mCurElem == mElems.end())
            mCurElem = mElems.begin();
    }

    return *mCurElem;
}


#endif // ROUNDROBIN_H_INCLUDED
