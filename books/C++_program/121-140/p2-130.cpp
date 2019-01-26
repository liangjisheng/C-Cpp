#include <iostream.h>
enum Color {Red,Yellow,Green,White};
//Բ��Circle�Ķ���
class Circle {  
    float radius;
public:
    Circle(float r) {radius=r;}
    float Area() {
        return 3.1416*radius*radius;
    }
};
//������Table�Ķ���
class Table {  
    float height;
public:
    Table(float h) {height=h;}
    float Height() {
        return height;
    }
};
//Բ����RoundTable�Ķ���
class RoundTable:public Table,public Circle {
    Color color;
public:
    RoundTable(float h,float r,Color c); //���캯��
    int GetColor() {
       return color;
    }
};
//Բ�����캯���Ķ���
RoundTable::RoundTable(float h,float r,Color c):Table(h),Circle(r)
{
    color=c;
}
//main()�����Ķ���
main() {
    RoundTable cir_table(15.0,2.0,Yellow);
    
    cout<<"The table properties are:"<<endl;
    //����Height��ĳ�Ա����
    cout<<"Height="<<cir_table.Height()<<endl;

    //����circle��ĳ�Ա����
    cout<<"Area="<<cir_table.Area()<<endl; 

    //����RoundTable��ĳ�Ա����
    cout<<"Color="<<cir_table.GetColor()<<endl;  
}
