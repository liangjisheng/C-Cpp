#include <iostream.h>
//����һ��ö������
enum Color {Red,Yellow,Green,White};
//Բ��Circle�Ķ���
class Circle {  
    float radius;
public:
    Circle(float r) {
        radius=r;
        cout<<"Circle initialized!"<<endl;
    }
    ~Circle() {  //��������
          cout<<"Circle  destroyed!"<<endl;
    }
    float Area() {
        return 3.1416*radius*radius;
    }
};
//������Table�Ķ���
class Table {  
    float height;
public:
    Table(float h) {
        height=h;
        cout<<"Table initialized!"<<endl;
    }
    ~Table() {  //���캯��
        cout<<"Table destroyed!"<<endl;
    }
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
    ~RoundTable() {  //���캯��
        cout<<"RoundTable destroyed!"<<endl;
    }
};
//Բ�����캯���Ķ���
RoundTable::RoundTable(float h,float r,Color c):Table(h),Circle(r)
{
    color=c;
    cout<<"RoundTable initialized!"<<endl;
}
//���Զ�̳��й��캯��������������ִ�з�ʽ
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
