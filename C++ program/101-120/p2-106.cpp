#include <iostream.h>
//����rect��
class rect {
    int length;
    int width;
    int area;
public:
    rect(int l=1,int w=1)
    {
        length=l;
        width=w;
        area=length*width;
    }
    void show_rect(char *name)
    { 
		cout<<name<<":"<<endl;
        cout<<"length="<<length<<endl;
        cout<<"width="<<width<<endl;
        cout<<"area="<<area<<endl;
    }
};
//����ʹ��rect��
void main(void)
{
    //��rect�ഴ������
    rect a;
    rect b(2);
    rect c(2,3);

    //���ö���ĺ�����ʾ�����е�����
    a.show_rect("a");
    b.show_rect("b(2)");
    c.show_rect("c(2,3)");
}
