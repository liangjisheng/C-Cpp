#include <iostream.h>  //����iostream.hͷ�ļ�
main()
{
    //�ַ����ͱ���������
    char c1='A';
    char c2;

    //�ַ����ݵ����㼰���
    c2=c1+32;
    cout<<"c1="<<c1<<endl;
    cout<<"c2="<<c2<<endl;

    //����ַ���ASCII��	
    cout<<c1<<" : "<<int(c1)<<endl;
    cout<<c2<<" : "<<int(c2)<<endl;
    cout<<'$'<<" : "<<int('$')<<endl;
	
    //�����ַ�
    cout<<"c1 c2"<<endl;
    cin>>c1>>c2;
    cout<<"c1="<<c1<<"  c2="<<c2<<endl;
}
