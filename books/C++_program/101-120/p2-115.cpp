#include<iostream.h>
//��struct�ؼ��ֶ���ex_class��
struct ex_class {
    ex_class(int n=1): value(n) {}
    void set_value(int n) {
         value=n;
    }
    show_obj(char *name) {
		cout<<name<<": "<<value<<endl;
    }
private:
    int value;
}
//���� ex_class��
main()
{
    //��ex_class��������
    ex_class a,b(3);
    
    a.show_obj("a");
    b.show_obj("b");

    a.set_value(100);
    b.set_value(200);

    a.show_obj("a");
    b.show_obj("b");
}
