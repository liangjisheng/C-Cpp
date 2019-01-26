#ifndef ASSOCIATIVEARRAY_H_INCLUDED
#define ASSOCIATIVEARRAY_H_INCLUDED

// 使用非整数数组索引，重载operator[]

template<typename T>
class AssociativeArray
{
public:
    AssociativeArray();
    virtual ~AssociativeArray();
    T& operator[] (const std::string& key);
    const T& operator[] (const std::string& key) const;
private:

};

#endif // ASSOCIATIVEARRAY_H_INCLUDED
