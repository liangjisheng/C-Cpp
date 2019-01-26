
//**********************************************************************************
//main.cpp
//实例化 模版函数 M_swap 并交换两个实参的值
//**********************************************************************************

#include <iostream>
#include <string>
#include "M_swap.h"

using namespace std;

class Box{
    public:
        Box(double wi=1,double le=1,double he=1):w(wi),l(le),h(he)
        {cout<<"Box Constructor!\n";}
        ~Box() {cout<<"Destructor of Box!\n";}
        double getWidth() const{return w;}
        double getLength()const{return l;}
        double getHeight()const{return h;}
        double getVolume()const{return w*l*h;}
        void setWidht(int wi) {w=wi;}
        void setLenght(int le){l=le;}
        void setHeight(int he){h=he;}

    private:
        double w;
        double l;
        double h;
};

int main()
{
    int    i[2]={22 ,66 };
    char   c[2]={'a','b'};
    string s[2]={string(7,'n'),string(6,'v')};
    Box    b[2]={Box(12,12,12),Box(2,2,2)};

    cout<<"--------------------------------------\n";
    cout<<"First:\t"<<i[0]<<"\tSecond:\t"<<i[1]<<endl;
    cout<<"First:\t"<<c[0]<<"\tSecond:\t"<<c[1]<<endl;
    cout<<"First:\t"<<s[0]<<"\tSecond:\t"<<s[1]<<endl;
    cout<<"First:\t"<<b[0].getVolume()<<"\tSecond:\t"<<b[1].getVolume()<<endl<<endl;
    cout<<"--------------------------------------\n";
    M_swap(i[0],i[1]);
    M_swap(c[0],c[1]);
    M_swap(s[0],s[1]);
    M_swap(b[0],b[1]);
    cout<<"--------------------------------------\n";
    cout<<"First:\t"<<i[0]<<"\tSecond:\t"<<i[1]<<endl;
    cout<<"First:\t"<<c[0]<<"\tSecond:\t"<<c[1]<<endl;
    cout<<"First:\t"<<s[0]<<"\tSecond:\t"<<s[1]<<endl;
    cout<<"First:\t"<<b[0].getVolume()<<"\tSecond:\t"<<b[1].getVolume()<<endl<<endl;
    cout<<"--------------------------------------\n";

	system("pause");
    return 0;
}