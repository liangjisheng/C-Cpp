#include<iostream.h>
//����Box
class Box {
    int width,height;
public:
    void SetWidth(int w) {
        width=w;
    }
    void SetHeight(int h) {
        height=h;
    }
    int GetWidth() {return width;}
    int GetHeight() {return height;}
};
//������ColoredBox
class ColoredBox:public Box
{
    int color;
public:
    void SetColor(int c){
        color=c;
    }
    int GetColor() {return color;}
};
// ��main()�в��Ի����������
main(void)
{
    //������ʹ��ColoredBox��Ķ���
    ColoredBox cbox;
    cbox.SetColor(3);       //ʹ���Լ��ĳ�Ա����
    cbox.SetWidth(150);     //ʹ�û���ĳ�Ա����
    cbox.SetHeight(100);    //ʹ�û���ĳ�Ա����
 
    cout<<"cbox:"<<endl;
    cout<<"Color:"<<cbox.GetColor()<<endl;    //ʹ���Լ��ĳ�Ա����
    cout<<"Width:"<<cbox.GetWidth()<<endl;   //ʹ�û���ĳ�Ա����
    cout<<"Height:"<<cbox.GetHeight()<<endl;  //ʹ�û���ĳ�Ա����
    //cout<<cbox.width; Error!  
}
