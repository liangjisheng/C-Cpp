#include <iostream.h>
#include <stdlib.h>
//����timer��
class timer{  
    long minutes;
public:
    //�������س�Ա����
    settimer(char *m) { 
        minutes = atoi(m);
    };
    //�������س�Ա����
    settimer(int h, int m) { 
        minutes = 60*h+m ;
    };
    //�������س�Ա����
    settimer(double h) { 
        minutes = (int) 60*h ;
    };
    long getminutes(void) { return minutes; };
};
//main()�����Ķ���
main(void){
    timer start,finish;   //��������

    //ʹ�����س�Ա����
    start.settimer(8,30);
    finish.settimer(9,40); 
	cout<<"finish.settimer(9,40)-start.settimer(8,30):";
    cout<<finish.getminutes()-start.getminutes()<<endl;  

    //ʹ�����س�Ա����
    start.settimer(2.0);
    finish.settimer("180"); 
	cout<<"finish.settimer(\"180\")-start.settimer(2.0):";
    cout<<finish.getminutes()-start.getminutes()<<endl;  

  return 0;
}
