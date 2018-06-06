#ifndef ASSOCIATIVEARRAY_H_INCLUDED
#define ASSOCIATIVEARRAY_H_INCLUDED

// ʹ�÷�������������������operator[]

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
