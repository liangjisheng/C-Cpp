#include <iostream>
#include <random>

using namespace std;

int main()
{
    // random_device ���治�ǻ������������������������һ��
    // �������棬Ҫ����������һ�����������ɲ�ȷ���������
    // Ӳ��������ͨ������ԭ�����ɡ�
    // ����������������������������(entropy)���������
    // random_device��ʹ�õ��ǻ��������α���������������ô
    // ������entropy()�������ص�ֵΪ0.0;���������Ӳ���豸
    // �򷵻ط�0�����ֵ�Ƕ������豸���صĹ���

    random_device rnd;
    cout << "Entropy: " << rnd.entropy() << endl;
    cout << "Min value: " << rnd.min()
        << ", Max value: " << rnd.max() << endl;
    cout << "Random number: " << rnd() << endl;

    return 0;
}



// ��random_device�⣬C++11����������������α���������

// ����ͬ������(linear congruential engine),�����Ҫʹ��
// ����������������У���ô��Ӧ��ʹ������ͬ������

// 3��α����������У�÷ɭ��ת�㷨(Mersenne, twister)���ɵ�
// �����������ߡ�
template <class UIntType, size_t w, size_t n, size_t m, size_t r,
        UIntType a, size_t u, UIntType d, size_t s,
        UIntType b, size_t t, UIntType c, size_t l, UIntType f>
class mersenne_twister_engine
{
    ...
};

// ����λ����(subtract with carry)����Ҫ�󱣴�25������״̬
// ���������������÷ɭ��ת�㷨
