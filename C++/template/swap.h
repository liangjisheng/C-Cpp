#include"iostream"

template<class T>
void swap(T* x,T* y)
{
    std::cout<<"swap(T*,T*) called.\n";
    if(*x!=*y) {
        T tmp=*x;
        *x=*y;
        *y=tmp;
    }
}

void swap(int& x,int& y)
{
    std::cout<<"swap(int&,int&) called.\n";
    if(x!=y) {
        x^=y;
        y^=x;
        x^=y;
    }
}
