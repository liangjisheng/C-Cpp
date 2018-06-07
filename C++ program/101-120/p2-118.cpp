#include <iostream.h>
//���帴����
class complex{
    float  real;       //ʵ��
    float  image;     //�鲿
public:
    //���ص������"+"��ԭ��
    complex operator+ (complex right);
    //���ظ�ֵ�����"="�Ķ���
    complex operator= (complex right);
    void set_complex(float re, float im);
    void put_complex(char *name);
};
//���ؼӷ������"+"�Ķ���
complex complex::operator+ (complex right) {
    complex temp;
    temp.real = this->real + right.real;
    temp.image = this->image + right.image;
    return temp;
}
//���ؼӸ�ֵ�����"="�Ķ���
complex complex::operator= (complex right) {   
        this->real = right.real;
        this->image = right.image;
        return *this;
}
//����set_complex()��Ա����
void complex::set_complex(float re, float im) {
        real = re;
        image = im;
}
//����put_complex()��Ա����
void complex::put_complex(char *name) {
        cout<<name<<": ";
        cout << real << ' ';
        if (image >= 0.0 ) cout << '+';
        cout << image << "i\n";
}
//��main()������ʹ��complex��Ķ���
main(void)
{
    complex A, B, C;  //������������

    //���ø���������ֵ
    A.set_complex(1.2, 0.3);
    B.set_complex(-0.5, -0.8);

    //��ʾ��������
    A.put_complex("A");
    B.put_complex("B");

    //��ֵ���㣬��ʾ���
    C = A;
    C.put_complex("C=A");

    //�ӷ�����ֵ���㣬��ʾ���
    C = A + B;
    C.put_complex("C=A+B");
    return 0;
}
