#include<iostream.h>
//����һ������static���ݳ�Ա����
class ex
{
    static int num;      //static���ݳ�Ա
public:
    ex() {num++;}
    ~ex() {num--;}
    disp_count() {
       cout<<"The current instances count:";
       cout<<num<<endl;
    }
};
int ex::num=0;    //����static���ݳ�Ա�ĳ�ֵ
//main()��������ex��
main()
{
    ex a;
    a.disp_count();

    ex *p;
    p=new ex;
    p->disp_count();

    ex x[10];
    x[0].disp_count();

    delete p;
    a.disp_count();
}
