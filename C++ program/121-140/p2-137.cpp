#include <iostream>
#include <string>

using namespace std;

//�����ַ���(string)����
void main()
{

    //����string����
    string s1,s2;

    //string����ĸ�ֵ����
    s1="One";
    s2="Two";
    cout<<"s1="<<s1<<endl;
    cout<<"s2="<<s2<<endl;

    //string�������������
    string s3;
    s3=s1+" and "+s2;
    cout<<"s3="<<s3<<endl;

    //��ϸ�ֵ��������
    s3+=" and Three";
    cout<<"s3="<<s3<<endl;

    //�Ƚ����㼰������ʾ
    for (int i=1;i<=3;i++) {
        cout<<"---------------------"<<endl;
        cout<<"s1=";
        cin>>s1;
        cout<<"s2=";
        cin>>s2;
        if (s1<s2)   //С��
            cout<<s1<<" < "<<s2<<endl;
        if (s1<=s2)  //С�ڵ���
        cout<<s1<<" <= "<<s2<<endl;
        if (s1==s2)  //����
        cout<<s1<<" == "<<s2<<endl;
        if (s1>s2)   //����
        cout<<s1<<" > "<<s2<<endl;
        if (s1>=s2)  //���ڵ���
        cout<<s1<<" >= "<<s2<<endl;
        if (s1!=s2)  //����
            cout<<s1<<" != "<<s2<<endl;
    }
}
