#include <iostream.h>
//定义一个枚举类型
enum Color {Red,Yellow,Green,White};
//圆类Circle的定义
class Circle {  
    float radius;
public:
    Circle(float r) {
        radius=r;
        cout<<"Circle initialized!"<<endl;
    }
    ~Circle() {  //析构函数
          cout<<"Circle  destroyed!"<<endl;
    }
    float Area() {
        return 3.1416*radius*radius;
    }
};
//桌子类Table的定义
class Table {  
    float height;
public:
    Table(float h) {
        height=h;
        cout<<"Table initialized!"<<endl;
    }
    ~Table() {  //构造函数
        cout<<"Table destroyed!"<<endl;
    }
    float Height() {
        return height;
    }
};
//圆桌类RoundTable的定义
class RoundTable:public Table,public Circle {
    Color color;
public:
    RoundTable(float h,float r,Color c); //构造函数
    int GetColor() {
       return color;
    }
    ~RoundTable() {  //构造函数
        cout<<"RoundTable destroyed!"<<endl;
    }
};
//圆桌构造函数的定义
RoundTable::RoundTable(float h,float r,Color c):Table(h),Circle(r)
{
    color=c;
    cout<<"RoundTable initialized!"<<endl;
}
//测试多继承中构造函数和析构函数的执行方式
main() {
    RoundTable cir_table(15.0,2.0,Yellow);
    
    cout<<"The table properties are:"<<endl;
    //调用Height类的成员函数
    cout<<"Height="<<cir_table.Height()<<endl;

    //调用circle类的成员函数
    cout<<"Area="<<cir_table.Area()<<endl; 

    //调用RoundTable类的成员函数
    cout<<"Color="<<cir_table.GetColor()<<endl;  
}
