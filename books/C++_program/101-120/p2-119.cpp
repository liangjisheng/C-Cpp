// Example of the friend class
#include <iostream.h>
//����YourClass�࣬
class YourClass
{
//ָ��YourOtherClass��������Ԫ��
friend class YourOtherClass;  
private:
    int num;
public:
    YourClass(int n){num=n;}
    display(char *YCname){
        cout<<YCname<<".num :";
	    cout<<num<<endl;
    }
};
//����YourOtherClass������YourClass�����Ԫ��
class YourOtherClass
{
public:
    //ʹ��YourClass���˽�г�Ա
    void disp1(YourClass yc,char *YCname){ 
         cout<<YCname<<".num :";
        cout<<yc.num<<endl;   
    }
    //ʹ��YourClass��Ĺ�����Ա
    void disp2(YourClass yc,char* YCname){
        yc.display(YCname);       
    }
};
//��main()�����д�����ʹ��YourClass��YourOtherClass�����
main(void)
{
    //����YourClass�����
    YourClass a(10),b(100);

    //��ʾa��b�����ֵ
    cout<<"YourClass:"<<endl;
    a.display("a");
    b.display("b");

    //����YourOtherClass�����
    YourOtherClass temp;

    //ͨ��temp��ʾa��b�����ֵ
    cout<<"YourOtherClass:"<<endl;
    temp.disp1(a,"a");
    temp.disp2(b,"b");
}
