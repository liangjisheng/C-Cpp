#include <iostream>
#include <bitset>
using namespace std;

int main()
{
    // bitset是固定长度的位集，以长度作为模板参数
    bitset<10> myBitset;
    // set() 设置某位为true
    myBitset.set(3);
    myBitset.set(6);
    // operator[]
    myBitset[8] = true;
    myBitset[9] = myBitset[3];

    // test()访问某位
    if(myBitset.test(3))
        cout << "Bit 3 is set!" << endl;

    // bitset以包含0和1字符的string的形式进行流式处理
    cout << myBitset << endl;

    // 输出的string的最左边字符表示最高位，符合我们对二进制
    // 数表示方法的直观看法

    cout << endl;
    auto str1 = "0011001100";
    auto str2 = "0000111100";
    bitset<10> bitsOnes(str1);
    bitset<10> bitsTwos(str2);
    auto bitsThree = bitsOnes & bitsTwos;
    cout << bitsThree << endl;
    bitsThree <<= 4;
    cout << bitsThree << endl;

    return 0;
}
