#include <iostream>
#include <string>

using namespace std;

//�����ַ���(string)����
void main()
{
    //����string����,����ʾ
    string s1;
    string s2="ABCDEFGHIJK";
    string s3=s2;
    string s4(20,'A');
    string s5(s2,3,3);
    cout<<"s1="<<s1<<endl;
    cout<<"s2="<<s2<<endl;
    cout<<"s3="<<s3<<endl;
    cout<<"s4="<<s4<<endl;
    cout<<"s5="<<s5<<endl;

    //Ϊstring������������,����ʾ
    cout<<"s1=";
    cin>>s1;
    cout<<"s2=";
    cin>>s2;
    cout<<"s3=";
    cin>>s3;
    cout<<"s4=";
    cin>>s4;
    cout<<"s5=";
    cin>>s5;

    cout<<"s1="<<s1<<endl;
    cout<<"s2="<<s2<<endl;
    cout<<"s3="<<s3<<endl;
    cout<<"s4="<<s4<<endl;
    cout<<"s5="<<s5<<endl;
}
