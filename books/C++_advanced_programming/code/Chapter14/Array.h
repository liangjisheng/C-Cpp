#ifndef ARRAY_H_INCLUDED
#define ARRAY_H_INCLUDED

#include <stddef.h>
#include <stdexcept>

template <typename T>
class Array{
public:
    // Create an array with a default size that will grow as needed
    Array();
    virtual ~Array();

    // Disallow assignment and pass-by-value
    Array<T>& operator=(const Array<T>& rhs) = delete;
    Array(const Array<T>& src) = delete;

    // Return the value at index x. If index x does not exist in the array
    // throw an exception of type out_of_range.
    T getElementAt(size_t x) const;

    // Sets the value at index x to val. If index is out of range,
    // allocates more space to make it in range
    void setElementAt(size_t x,const T& val);

    T& operator[](size_t x);
    const T& operator[](size_t x) const;

private:
    static const size_t kAllocSize = 4;
    void Resize(size_t newsize);
    // Sets all elements to 0
    void initializeElements();
    T* mElems;
    size_t mSize;
};


template<typename T>
Array<T>::Array()
{
    mSize = kAllocSize;
    mElems = new T[mSize];
    initializeElements();
}

template<typename T>
Array<T>::~Array()
{
    delete [] mElems;
    mElems = nullptr;
}

template<typename T>
T Array<T>::getElementAt(size_t x) const
{
    if(x >= mSize)
        throw std::out_of_range("");
    return mElems[x];
}

template<typename T>
void Array<T>::setElementAt(size_t x,const T& val)
{
    if(x >= mSize)
        Resize(x + kAllocSize);
    mElems[x] = val;
}

template<typename T>
T& Array<T>::operator[](size_t x)
{
    std::cout << "call non-const operator[]" << std::endl;
    if(x >= mSize)
        Resize(x + kAllocSize);
    return mElems[x];
}

template<typename T>
const T& Array<T>::operator[](size_t x) const
{
    std::cout << "call const operator[] " ;
    if(x >= mSize)
        throw std::out_of_range("");
    return mElems[x];
}

template<typename T>
void Array<T>::Resize(size_t newsize)
{
    // Make a copy of the current elements pointer and size
    T* oldElems = mElems;
    size_t oldSize = mSize;
    // Create new bigger array
    mElems = new T[newsize];
    initializeElements();
    mSize = newsize;

    for(size_t i = 0; i < oldSize; ++i)
            mElems[i] = oldElems[i];

    delete []oldElems;
    oldElems = nullptr;
}

template<typename T>
void Array<T>::initializeElements()
{
    for(size_t i = 0; i < mSize; ++i)
        mElems[i] = T();
}


#endif // ARRAY_H_INCLUDED
