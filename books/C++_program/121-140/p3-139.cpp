//���ݰ뾶����Բ���ܳ������
#include <iostream.h>
const float PI=3.1416;        //��������(ֻ������)PIΪ3.1416
float fCir_L(float);           //�����Զ��庯��fCir_L()��ԭ�� 
float fCir_S(float);           //�����Զ��庯��fCir_S()��ԭ��  

//������main()���� 
main() 
{ 
    float r,l,s;             //����3������
    
    cout<<"R=";          //��ʾ�ַ���
    cin>>r;              	//��������
    l=fCir_L(r);          //����Բ���ܳ�����ֵ������l 
    s=fCir_S(r);          //����Բ���������ֵ������s 
    cout<<"l="<<l;       //��ʾ������
    cout<<"\ns="<<s;                 
}   

//�������Բ���ܳ��ĺ���fCir_L()
float fCir_L(float x)
{ 
    float z=-1.0;         //�����ֲ�����
    if (x>=0.0)          //�����������0�������Բ���ܳ�
        z=2*PI*x;
    return(z);          //���غ���ֵ 
} 

//�������Բ������ĺ���fCir_S()
float fCir_S(float x)
{ 
    float z=-1.0;         //�����ֲ�����
    if (x>=0.0)          //�����������0�������Բ�����
        z=PI*x*x;
    return(z);           //���غ���ֵ 
}
