#include <iostream>
#include <random>

using namespace std;

int main()
{
    // random_device 引擎不是基于软件的随机数生成器，这个一个
    // 特殊引擎，要求计算机连接一个能真正生成不确定随机数的
    // 硬件，例如通过物理原理生成。
    // 随机数生成器的质量有随机数的熵(entropy)决定。如果
    // random_device类使用的是基于软件的伪随机数生成器，那么
    // 这个类的entropy()方法返回的值为0.0;如果连接了硬件设备
    // 则返回非0，这个值是对连接设备的熵的估计

    random_device rnd;
    cout << "Entropy: " << rnd.entropy() << endl;
    cout << "Min value: " << rnd.min()
        << ", Max value: " << rnd.max() << endl;
    cout << "Random number: " << rnd() << endl;

    return 0;
}



// 除random_device外，C++11还定义了其它三个伪随机数引擎

// 线性同余引擎(linear congruential engine),如果需要使用
// 高质量的随机数序列，那么不应该使用线性同余引擎

// 3个伪随机数引擎中，梅森旋转算法(Mersenne, twister)生成的
// 随机数质量最高。
template <class UIntType, size_t w, size_t n, size_t m, size_t r,
        UIntType a, size_t u, UIntType d, size_t s,
        UIntType b, size_t t, UIntType c, size_t l, UIntType f>
class mersenne_twister_engine
{
    ...
};

// 带进位减法(subtract with carry)引擎要求保存25个整数状态
// 随机数的质量不如梅森旋转算法
