#include <iostream.h>
//����������
class Date    
{
    //������Ԫ�����������������
    friend istream& operator >> (istream& input,Date& dt ); 
    //������Ԫ����������������
    friend ostream& operator<< (ostream& output,Date& dt ); 
    int mo, da, yr;
public:
    Date(void){  //�޲������캯��
        yr = 0;
        mo = 0; 
        da = 0; 
    }
    Date( int y, int m, int d )   //���������캯��
    {
        yr = y;
        mo = m; 
        da = d; 
    }
};
//����">>"��������غ���
istream& operator >> ( istream& input, Date& dt )
{
    cout<<"Year:";
    input>>dt.yr;
    cout<<"Month:";
    input>>dt.mo;
    cout<<"Day:";
    input>>dt.da;
    return input;
}

//����"<<"��������غ���
ostream& operator<< ( ostream& output, Date& dt )
{
   output<< dt.yr << '/' << dt.mo << '/' << dt.da<<endl;
   return output;
}

//��main()�����в���Date��Ĳ��루<<������ȡ��>>�������
void main()
{
    //��������
    Date dt1(2002,5,1),dt2;

    //��ʾdt1����
    cout<<dt1;

    //��dt2���������������
    cin>>dt2;
    cout<<dt2;
}
