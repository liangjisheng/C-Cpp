#include<iostream.h>
//����һ��ȫ��Ϊpublic:ģʽ����
class ex 
{
public:
     int value;
     void set(int n) { 
         value=n;
     }
     int get(void) {
        return value;
     }
};
//����ʹ��ex��
main()
{
    ex a;    //��������

    //����ͨ����Ա�������ʶ�������
    a.set(100);
	cout<<"a.get()=";
    cout<<a.get()<<endl;

    //����ֱ�ӷ��ʶ�������ݳ�Ա
    a.value=200; 
	cout<<"a.value=";
    cout<<a.value<<endl;
}
