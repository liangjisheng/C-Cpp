#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

int main()
{
    list<int> coll;
    list<int>::iterator pos;

    // insert elements from 20 to 40
    for(int i=20;i<=40;++i)
        coll.push_back(i);

    // find position of element with value 3,
    // if not find,so pos gets coll.end();
    pos = find(coll.begin(),coll.end(),3);

    // reverse the order of elements between element and the
    // end,because pos is coll.end() it reverse an empty range
    reverse(pos,coll.end());

    // find positions of values 25 and 35
    list<int>::iterator pos25,pos35;
    pos25 = find(coll.begin(),coll.end(),25);
    pos35 = find(coll.begin(),coll.end(),35);

    // print the maximum of the corresponding range
    // -note: including pos25 but excluding pos35
    cout<<"max: "<<*max_element(pos25,pos35)<<endl;

    // process the elements including the last position
    cout<<"max: "<<*max_element(pos25,++pos35)<<endl;

    return 0;
}


// �����㲢��֪��Ԫ��25��Ԫ��35��ǰ���ϵ�������������Ƿ����Ҳ�Ĵ�����
// ����������õ��������ȡ������(random access iterators),�����ʹ��operator<���м��
if(pos25 < pos35){
    // only [pos25,pos35) is valid
}
else if(pos35 < pos25){
    // only [pos35,pos25) is valid
}
else{
    // both are equal,so both must be end()
}


// ��������ϵĲ��������ȡ���������ǻ����ûʲôֱ���˵��ķ���ȷ��
// �ĸ���������ǰ����ʱ���������ҪһЩ�仯������һ����������������
// ��Ѱ����ֵ�������˽��ĸ�ֵ���ҵ����ĸ�ֵ���ҵ�
pos25 = find(coll.begin(),coll.end(),25);
pos35 = find(coll.begin(),pos25,35);
if(pos35 != pos25){
    // pos35 is in front of pos25,so only [pos35,pos25) is valid
}
else{
    pos35 = find(pos25,coll.end(),35);
    if(pos35 != pos25){
        // pos25 is in front of pos35,so only [pos25,pos35) is valid
    }
    else{
        // both are euqal,so both must be end()
    }
}


// ��Ȼ�����������ĸ��У�����ֱ���ҵ�25����35��һ�γ��ֵ�λ��
pos = find_if(coll.begin(),coll.end(),
              compose_f_gx_hx(logical_or<bool>(),
                              bind2nd(equal_to<int>(),25),
                              bind2nd(equal_to<int>(),35)));
switch(*pos){
case 25:
    // element with value 25 comes first
    pos25 = pos;
    pos35 = find(++pos,coll.end(),35);
    break;
case 35:
    // element with value 35 comes first
    pos35 = pos;
    pos25 = find(++pos,coll.end(),25);
    break;
default:
    // no element with value 25 or 35 found
    break;
}

