#include <iostream>
#include <utility>
#include <string>
using namespace std;

int main()
{
    pair<string,int> myPair("hello",5);
    pair<string,int> myOtherPair;
    // Can assign directory to first and second
    myOtherPair.first = "hello";
    myOtherPair.second = 6;
    // Copy constructor
    // pair ��ʹ��ָ����ΪΣ�յģ�pair���ƹ��캯���͸�ֵ�����ֻ
    // ��ָ�����ͽ���ǳ���ƺ͸�ֵ����pair��Ӧ��ʹ������ָ��
    pair<string,int> myThirdPair(myOtherPair);
    // operator<
    if(myPair < myOtherPair)
        cout << "myPair is less than myOtherPair" << endl;
    else
        cout << "myPair is greater than myOtherPair" << endl;

    // operator==
    if(myOtherPair == myThirdPair)
        cout << "myOtherPair is equal to myThirdPair" << endl;
    else
        cout << "myOtherPair is not equal to myThirdPair" << endl;

    return 0;
}
