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


// 假设你并不知道元素25和元素35的前后关系，甚至连它们是否存在也心存疑虑
// 如果你手上用的是随机存取迭代器(random access iterators),则可以使用operator<进行检查
if(pos25 < pos35){
    // only [pos25,pos35) is valid
}
else if(pos35 < pos25){
    // only [pos35,pos25) is valid
}
else{
    // both are equal,so both must be end()
}


// 如果你手上的并非随机存取迭代器，那还真的没什么直截了当的方法确定
// 哪个迭代器在前。此时解决方法需要一些变化：不是一口气在整个区间中
// 搜寻两个值，而是了解哪个值先找到，哪个值后找到
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


// 当然，还有其他的高招，可以直接找到25或者35第一次出现的位置
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

