#include <iostream>
#include <string>

using namespace std;

//�����ַ���(string)����
void main()
{
    //����string����,����ʾ
    string s1="This";
    string s2="book.";
    cout<<"s1: "<<s1<<endl;
    cout<<"s2: "<<s2<<endl;
    
    //ʹ��length��Ա����
    cout<<"s1.length()="<<s1.length()<<endl;
    cout<<"s2.length()="<<s2.length()<<endl;

    //ʹ��append��Ա����
    s1.append(s2);
    cout<<"s1: "<<s1<<endl;

    //ʹ��find��Ա�������±�����
    int pos=s1.find('b');
    cout<<"s1["<<pos<<"]="<<s1[pos]<<endl;

    //ʹ��insert��Ա����
    s1.insert(pos," is a ");
    cout<<s1<<endl;

    //ʹ��assign��Ա����
    s1.assign("Good");
    cout<<s1<<endl;

}
