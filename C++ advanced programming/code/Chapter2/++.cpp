#include <iostream>

using namespace std;

int main()
{
    // ǰ��++����ԭ���ı�����ֱ�Ӹı䣬���õĻ����뽫+1֮���ֵ
    // ������һ���ֲ������ԭ���ı���������ڸ�ֵ��ԭ���ı���
    int i = 2;
    int res = ++i + ++i;
    cout << res << endl;        // 8
    cout << "i = " << i << endl << endl;    // 4

    i = 2;
    res = ++i + i++;
    cout << res << endl;        // 6
    cout << "i = " << i << endl << endl;    // 4

    i = 2;
    res = i++ + ++i;
    cout << res << endl;        // 6
    cout << "i = " << i << endl << endl;    // 4

    i = 2;
    res = i++ + i++;
    cout << res << endl;        // 5
    cout << "i = " << i << endl << endl;    // 4

    return 0;
}
