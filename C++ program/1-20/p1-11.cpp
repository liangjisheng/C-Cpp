#include <iostream.h>  //����iostream.hͷ�ļ�
main()
{
    //����bool����������ʼ��
    bool flag1=false,flag2=true; 
	
    //������������ͱ���
    cout<<"false:"<<false<<endl;
    cout<<"true: "<<true<<endl;
    cout<<"flag1="<<flag1<<endl;
    cout<<"flag2="<<flag2<<endl;

    //���������ĸ�ֵ�����
    int x=1;
    flag1=x>0;      //��Ź�ϵ������
    cout<<"flag1="<<flag1<<endl;
    flag2=flag1;    //bool���ͱ����໥��ֵ
    cout<<"flag2="<<flag2<<endl;

    //�����������紦��
    flag1=100; 
    cout<<"flag1="<<flag1<<endl;
    flag2=-100; 
    cout<<"flag2="<<flag2<<endl;
}
