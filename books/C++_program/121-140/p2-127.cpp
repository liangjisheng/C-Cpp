#include<iostream.h>
//�������First
class First {
    int  num;
    float grade;
public:
    //���캯��������
    First(int n,float v ) : num(n),grade(v)
    {
        cout<<"The First initialized"<<endl;
    }
    DispFirst(void) {
        cout<<"num="<<num<<endl;
        cout<<"grade="<<grade<<endl;
    }
};

//����������Second
class Second :public First {  
    double val;
public:
    //�޲������캯����ҪΪ����Ĺ��캯�����ò���
    Second(void):First(10000,0) {
        val=1.0;
        cout<<"The Second initialized"<<endl;
    }

    //���������캯����Ϊ����Ĺ��캯�����ò���
    Second(int n,float x,double dx):First(n,x) {
        val=dx;
        cout<<"The Second initialized"<<endl;
    }
    Disp(char *name){
        cout<<name<<".val="<<val<<endl;
        DispFirst();
    }
};

//main()�����д�����ʹ�����������
main() {
    //������������޲������캯��
	cout<<"Second s1;"<<endl;
    Second s1;
	cout<<"s1.Disp(\"s1\");"<<endl;
	s1.Disp("s1");

    //������������в������캯��
	cout<<"Second s2(10002,95.7,3.1415926); "<<endl;
    Second s2(10002,95.7,3.1415926); 
	cout<<"s2.Disp(\"s2\");"<<endl;	
    s2.Disp("s2");
}
