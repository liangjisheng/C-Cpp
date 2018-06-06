#include <iostream>
#include <map>
#include <string>
using namespace std;

class Data
{
public:
    explicit Data(int val = 0) { mVal = val; }
    int getVal() const { return mVal; }
    void setVal(int val) { mVal = val; }
private:
    int mVal;
};

int main()
{
    map<int,Data> dataMap;
    // Using an initializer_list,insert()����ֵ�ǵ������Ͳ���ֵ
    // ��ɵ� pair,���ָ���ļ��Ѿ����ڣ���ôinsert()�����д
    // Ԫ��ֵ�����ص�pair�е�boolָ����insert()�Ƿ���� ������
    // �µļ�ֵ��
    // �������һ��auto�ؼ��֣�����Ϊretָ����ȷ������
    // pair<map<int,Data>::iterator, bool> ret;
    auto ret = dataMap.insert({1,Data(1)});
    if(ret.second) {
        cout << "Insert succeeded!" << endl;
    }else{
        cout << "Insert failed!" << endl;
    }

    // Using a pair object
    ret = dataMap.insert(make_pair(1,Data(6)));
    if(ret.second) {
        cout << "Insert succeeded!" << endl;
    }else{
        cout << "Insert failed!" << endl;
    }

    ret = dataMap.insert(make_pair(2,Data(2)));
    ret = dataMap.insert(make_pair(3,Data(3)));
    ret = dataMap.insert(make_pair(4,Data(4)));
    ret = dataMap.insert(make_pair(5,Data(5)));
    ret = dataMap.insert(make_pair(6,Data(6)));
    ret = dataMap.insert(make_pair(7,Data(7)));
    ret = dataMap.insert(make_pair(8,Data(8)));
    ret = dataMap.insert(make_pair(9,Data(9)));
    ret = dataMap.insert(make_pair(10,Data(10)));

    cout << endl;
    for(auto iter = dataMap.cbegin(); iter != dataMap.cend(); ++iter)
        cout << iter->second.getVal() << ' ';
    cout << endl;

    dataMap[1] = Data(4);
    cout << "change the dataMap[1] to 4 :" << endl;
    for(auto iter = dataMap.cbegin(); iter != dataMap.cend(); ++iter)
        cout << iter->second.getVal() << ' ';
    cout << endl;

    dataMap[1] = Data(6);
    cout << "change the dataMap[1] to 6 :" << endl;
    for(auto iter = dataMap.cbegin(); iter != dataMap.cend(); ++iter)
        cout << iter->second.getVal() << ' ';
    cout << endl;

    dataMap[1].setVal(100);
    cout << "change the dataMap[1] to 100 :" << endl;
    for(auto iter = dataMap.cbegin(); iter != dataMap.cend(); ++iter)
        cout << iter->second.getVal() << ' ';
    cout << endl;

    auto it = dataMap.find(2);
    if(it != dataMap.end())
        it->second.setVal(100);
    cout << "change the dataMap[2] to 100 :" << endl;
    for(auto iter = dataMap.cbegin(); iter != dataMap.cend(); ++iter)
        cout << iter->second.getVal() << ' ';
    cout << endl;

    cout << endl;
    cout << "There are " << dataMap.count(1) << " element with key 1" << endl;
    dataMap.erase(1);
    cout << "There are " << dataMap.count(1) << " element with key 1" << endl;

    // map֧��ͳһ��ʼ��
    map<string,int> m = {
      { "li", 123 },
      { "ji", 456 },
      { "sheng", 789 },
    };

    cout << endl;
    cout << m["li"] << endl;
    cout << m["ji"] << endl;
    cout << m["sheng"] << endl;

    return 0;
}
