#include<iostream.h>
//Y��Ĳ���ȫ����
class Y;

//X��Ķ���    
class X {   
public:
    void disp(Y py,char *name);   //��Ա����ԭ��
};

//����Y��
class Y {  
    //�����������Ԫ����
    //X���disp()Ϊ��������Ԫ����
    friend void X::disp(Y py,char *name);
     //��ͨ����putY() Ϊ��������Ԫ����
    friend void putY(Y& yc,char *name);         
private: //˽�г�Ա
    int num;
    dispY(char *name){    
        cout<<name<<".num="<<num<<endl;
    }
public: //������Ա����
    Y(int n){  
       num=n;
    }
};

//X���Ա������ʵ�ֲ���
void X::disp(Y py,char *name){
    cout<<"In X::disp():"<<endl;
    py.dispY(name);   //����Y���˽�к���
}

//��ͨ����putY()�Ķ���
void putY(Y& yc,char *name){
    cout<<"In getY:"<<endl;
    yc.dispY(name);
    cout<<name<<".num=";
    cout<<yc.num<<endl;
}

//��main()��������X��Y��Ĺ���
main()
{
    //����Y��X��Ķ���
    Y y1(100),y2(200);
    X x;

    //������Y������˽�г�Ա������ʾ
    //y1.dispY("y1");
    //y2.dispY("y2");

    //����X��������Ԫ������ʾ
    x.disp(y1,"y1");
    x.disp(y2,"y2");

    //��getY������ʾY��Ķ�����ʾ
    putY(y1,"y1");
    putY(y2,"y2");
}
