#include <iostream.h>
#include<string.h>
//����˫�ף�parent����
class parent {
    char  f_name[20];
    char  m_name[20];
    char  tel[10];
public:
    // parent��Ĺ��캯���������ȱʡֵ
    parent(char *p1="",char *p2="",char *p3="") {
        strcpy(f_name,p1);
        strcpy(m_name,p2);
        strcpy(tel,p3);
    }
    //��ʾparent���������
    show_parent(void) {    
        cout<<"The parent:"<<endl;
        cout<<"    father's name:"<<f_name<<endl;
        cout<<"    mother's name:"<<m_name<<endl;
        cout<<"    tel:"<<tel<<endl;
    }
};
//����student��
class student {
    int       num;
    char      name[20];
    float     grade;
    parent    pt;      
public:
    // student��Ĺ��캯��
    student(int n,char *str,float g,class parent t) {
        num=n;
        strcpy(name,str);
        grade=g;
        pt=t;
    }
    //��ʾstudent���������
    show_student(void) {
        cout<<"num:"<<num<<endl;
        cout<<"name:"<<name<<endl;
        cout<<"grade:"<<grade<<endl;
        pt.show_parent();
    }
};
//main()��������student��Ķ���
main(void)
{
    //����˫�׶���
    parent p1("ZhangHua","LiLan","83665215");

	//����ѧ������
    student st(10001,"ZhangHui",91.5,p1); 
	
    //��ʾѧ����Ϣ
	cout<<"p1:"<<endl;
	p1.show_parent();

    //��ʾѧ����Ϣ
	cout<<"st:"<<endl;
    st.show_student();
}
