#include <iostream>
#include <bitset>
using namespace std;

int main()
{
    // bitset�ǹ̶����ȵ�λ�����Գ�����Ϊģ�����
    bitset<10> myBitset;
    // set() ����ĳλΪtrue
    myBitset.set(3);
    myBitset.set(6);
    // operator[]
    myBitset[8] = true;
    myBitset[9] = myBitset[3];

    // test()����ĳλ
    if(myBitset.test(3))
        cout << "Bit 3 is set!" << endl;

    // bitset�԰���0��1�ַ���string����ʽ������ʽ����
    cout << myBitset << endl;

    // �����string��������ַ���ʾ���λ���������ǶԶ�����
    // ����ʾ������ֱ�ۿ���

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
