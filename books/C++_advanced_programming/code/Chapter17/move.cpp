#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class myClass
{
public:
    myClass();
    myClass(const myClass& src);
    myClass(const string& src) : mStr(src) {}
    // Move assignment operator
    myClass& operator=(myClass&& rhs) noexcept{
        if(this == &rhs)
            return *this;

        mStr = move(rhs.mStr);
        cout << "Move operator= (mStr=" << mStr << ")" << endl;
        return *this;
    }
    string getString() const { return mStr; }
private:
    string mStr;
};

myClass::myClass() : mStr("") {}

myClass::myClass(const myClass& src) : mStr(src.mStr) {}

int main()
{
    vector<myClass> vecSrc{ myClass("a"), myClass("b"), myClass("c")};
    vector<myClass> vecDst(vecSrc.size());
    move(vecSrc.begin(), vecSrc.end(), vecDst.begin());
    // move_backward()ʹ���˺�moveͬ�����ƶ����ƣ����ǰ��մ�
    // ���һ��Ԫ�����һ��Ԫ�ص�˳���ƶ�

    for(const auto& c : vecDst)
        cout << c.getString() << " ";
    cout << endl;

    return 0;
}
