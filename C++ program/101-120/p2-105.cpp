#include <iostream.h>
#include <stdlib.h>
//����timer��
class timer{
    long minutes;
public:
    //�޲������캯��
    timer(void) { 
        minutes =0;
    };
    //�ַ�ָ������Ĺ��캯��
    timer(char *m) { 
        minutes = atoi(m);
    };
    //�������͵Ĺ��캯��
    timer(int h, int m) { 
        minutes = 60*h+m ;
    };
    //˫���ȸ����͹��캯��
    timer(double h) { 
        minutes = (int) 60*h ;
    };
    long getminutes(void) { return minutes ; };
};
//main()�����Ķ���
main(void)
{
    //ʹ��double���͵Ĺ��캯����������
    timer start(8.30),finish(17.30);
	cout<<"finish(17.30)-start(8.30)=";
    cout<<finish.getminutes()-start.getminutes()<<endl;  

    //ʹ��charָ�����͵Ĺ��캯����������
    timer start0("500"),finish0("800");   //��������
	cout<<"finish0(\"800\")-start0(\"500\")=";
    cout<<finish0.getminutes()-start0.getminutes()<<endl;  

    //ʹ���޲������캯�������͹��캯����������
    timer start1;   
    timer finish1(3,30);  
	cout<<"finish1(3,30)-start1=";
    cout<<finish1.getminutes()-start1.getminutes()<<endl;  

    return 0;
}
