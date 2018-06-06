#include <iostream>
#include <vector>
#include <functional>

using namespace std;

// std::function ��һ����̬�ĺ��������װ�������ں���ָ�롣
// ���԰����κ��ܵ��õĶ���(�º�������Ա����ָ�룬����ָ��
// ��lambda���ʽ)��ֻҪ�����ͷ������ͷ��ϰ�װ�����ͼ��ɡ�

function<int(void)> multiplyBy2lambda(int x)
{
    // multiplyBy2lambda�ķ�������Ϊfunction<int(void)>
    // ���������ܲ���������һ�������ĺ�������lambda���ʽ��
    // ��������ǰ��xֵ�ĸ�������lambda���ʽ�е�x
    return [x] { return 2 * x; };
}


// ���Ա�д����lambda���ʽ��Ϊ�����ĺ�������ͨ�����ַ�ʽ
// ʵ�ֻص�����
void testCallBack(const vector<int>& vec,
                  const function<bool(int)>& callback)
{
    for(const auto& i : vec) {
        // Call callback. If it returns false,stop iteration.
        if(!callback(i))
            break;
        // Callback did not stop iteration.so print value
        cout << i << " ";
    }
    cout << endl;
}


int main()
{
    function<int(void)> fn = multiplyBy2lambda(5);
    cout << fn() << endl;


    // test callback
    vector<int> vec{1,2,3,4,5,6,7,8,9,10};
    testCallBack(vec,[](int i) { return i < 6;} );

    return 0;
}
