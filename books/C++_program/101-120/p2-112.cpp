#include<iostream.h>
//����һ������static���ݳ�Ա����
class ex
{
    static int num;      //static���ݳ�Ա
public:
    ex() {num++;}
    ~ex() {num--;}
    static disp_count(void) //static��Ա����
    {
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
    ex::disp_count();   //ֱ����������������þ�̬��Ա����

    delete p;
    ex::disp_count();  //ֱ����������������þ�̬��Ա����
}
