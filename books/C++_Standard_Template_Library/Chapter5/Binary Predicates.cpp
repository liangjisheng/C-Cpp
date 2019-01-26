
// Binary predicates 的典型用途，是比较两哥参数的特定属性。
// 例如，为了依照你自己的原则对元素排序，你必须以一个简单的
// predicate 形式提供这项元祖，如果元素本身不支持operator<
// 或者你想使用不同的排序原则，这就派上用场了

// 下面这个例子，根据每个人的姓名，对一组元素进行排序

#include <iostream>
#include <string>
#include <deque>
#include <algorithm>
using namespace std;

class Person{
public:
    string firstname() const;
    string lastname() const;
};

// binary function predicate
// - return whether a person is less than another person
bool personSortCirterion(const Person& p1,const Person& p2)
{
    return p1.lastname() < p2.lastname() ||
            (!(p1.lastname() < p2.lastname()) &&
             p1.firstname() < p2.firstname());
}

int main()
{
    deque<Preson> coll;
    ...
    sort(coll.begin(),coll.end(),   // range
         personSortCirterion);      // sort criterion
    ...

    return 0;
}
