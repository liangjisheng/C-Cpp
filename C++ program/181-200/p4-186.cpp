#include <iostream>
#include <string>
#include <map>

using namespace std;

//����map��ʵ��������(int)ӳ���ַ���(string)
typedef map<int, string> INT2STRING;

//����map����
void main()
{
    //����map����theMap
    INT2STRING theMap;
    INT2STRING::iterator theIterator,it;

    //��theMap�������������ݣ����ֺ��ַ������
    //ÿ��Ԫ����һ��ӳ���
    theMap.insert(INT2STRING::value_type(0,"Zero"));
    theMap.insert(INT2STRING::value_type(2,"Two"));
    theMap.insert(INT2STRING::value_type(4,"Four"));
    theMap.insert(INT2STRING::value_type(6,"Six"));
    theMap.insert(INT2STRING::value_type(8,"Eight"));

    //��ʾmap���������ж���
    cout<<"theMap.begin()--theMap.end():"<<endl;
    for (theIterator=theMap.begin();theIterator!=theMap.end();++theIterator){
        cout<<(*theIterator).first;
        cout<<","<<(*theIterator).second<<" ";
    }
    cout<<endl;

	//����map����key��Ωһ��
    theMap.insert(INT2STRING::value_type(0,"Zero"));
    theMap.insert(INT2STRING::value_type(1,"One"));
    theMap.insert(INT2STRING::value_type(2,"Two"));
    theMap.insert(INT2STRING::value_type(3,"Three"));
    theMap.insert(INT2STRING::value_type(4,"Four"));
    theMap.insert(INT2STRING::value_type(5,"Five"));
    theMap.insert(INT2STRING::value_type(6,"Six"));
    theMap.insert(INT2STRING::value_type(7,"Seven"));
    theMap.insert(INT2STRING::value_type(8,"Eight"));
    theMap.insert(INT2STRING::value_type(9,"Nine"));
    //������佫���ܲ��뵽map������
    theMap.insert(INT2STRING::value_type(5,"AAA"));

    //��ʾmap���������ж���
    cout<<"theMap.begin()--theMap.end():"<<endl;
    for (theIterator=theMap.begin();theIterator!=theMap.end();++theIterator){
        cout<<(*theIterator).first;
        cout<<","<<(*theIterator).second<<" ";
    }
    cout<<endl;

	//����������������ʾ�����е�Ԫ��
	cout<<"[theMap.lower_bound(3),theMap.upper_bound(8)] :"<<endl;
	for (it=theMap.lower_bound(3);it!=theMap.upper_bound(8);it++) {
	    cout<<(*it).first;
        cout<<","<<(*it).second<<" ";
	}
	cout<<endl;

	//��ʾtheMap��״̬��Ϣ
    cout<<"theMap.size():"<<theMap.size()<<endl;
    cout<<"theMap.max_size():"<<theMap.max_size()<<endl;
    cout<<"theMap.count(15):"<<theMap.count(15)<<endl;

    // �Ӽ������������֣���ʾ��Ӧ���ַ���
    string theString = "";
    int index;
    for( ; ; )
    {
        cout << "Enter \"q\" to quit, or enter a Number: ";
        cin >> theString;
        if(theString == "q")
            break;

        for(index = 0; index < theString.length(); index++){
            theIterator = theMap.find(theString[index] - '0');
            if(theIterator != theMap.end() ) 
                cout << (*theIterator).second << " ";
            else    
                cout << "[err] ";
        }
        cout << endl;
    }
}
