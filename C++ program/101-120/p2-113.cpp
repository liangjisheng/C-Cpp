#include <iostream.h>
class ex_class {
    int value;
public:
    ex_class(int n) {
        value=n;
        cout << "Stack initialized." << endl;
    }
    ~ex_class() {    
        cout << "The Object destroyed." <<endl;  
    }
    void set_value(int n);
    void show_val(char *name);
} ;

//�����ⶨ��������Ա����
inline void ex_class::set_value(int n) {
    value=n;
}
//�����ⶨ���������Ա����
void ex_class::show_val(char *name) {
	cout<<name<<": ";
    cout<<value<<endl;
}
//��main()�����в���ex_class��
main(void)
{
    //��������x��y
    ex_class x(100),y(200);

    //��ʾ���������
    x.show_val("x");
    y.show_val("y");

    //������ֵ������
    x.set_value(1);
    y.set_value(2);

    //��ʾ���������
    x.show_val("x");
    y.show_val("y");

    return 0;
}
