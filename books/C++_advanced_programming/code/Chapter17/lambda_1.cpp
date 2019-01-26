#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    auto basiclambda = []{ cout << "hello from lambda" << endl; };
    // ��ͨ���������﷨����lambda ���ʽ
    basiclambda();

    // ���ܲ����� lambda ���ʽ����������ܲ���������ʹ�ÿ�Բ���Ż��������
    auto parameters =
        [](int value) { cout << "The value is :" << value << endl; };
    parameters(2);

    // ��β��������
    auto returninglambda = [](int a, int b) -> int { return a + b; };
    cout << returninglambda(11,22) << endl;

    // lambda ���ʽ���������������ڲ�׽����
    double data = 1.23;
    // ֻд����������ʾ��ֵ��׽
    auto capturinglambda = [data] { cout << "Data = " << data << endl; };
    capturinglambda();

    const double cData = 2.34;
    auto cCapturinglambda =
        [cData] { cout << "const Data = " << cData << endl; };
    cCapturinglambda();


    // ����lambda��ʾʽ������������������Ĭ�ϱ��Ϊconst,
    // ���ʾ����ʹ��lambda���ʽ�а�ֵ��׽�˷�const������
    // lambdaҲ�����޸��丱������lambda���ʽָ��Ϊmutable,
    // �Ϳ��԰Ѻ���������������Ϊ��const
    double d1 = 3.45;
    auto capturinglambda_1 =
        [d1] () mutable { d1 *= 2; cout << "Data = " << d1 << endl; };
    capturinglambda_1();
    // ���ָ����mutable,�ͱ��������ָ��Բ���ţ���ʹԲ����Ϊ�գ�Ҳ�����


    // �ڱ�����ǰ����&,�Ϳ��԰����ò�׽����
    double d2 = 4.56;
    auto capturinglambda_2 =
        [&d2] { d2 *= 2; cout << "Data2 = " << d2 << endl; };
    capturinglambda_2();


    // [=]: ͨ��ֵ��׽���б���
    // [&]: ͨ�����ò�׽�������е����б���
    // [&x]: ֻͨ��Ӧ�ò�׽x������׽��������
    // [x]: ֻͨ��ֵ��׽x������׽��������
    // [=,&x,&y]: Ĭ��ͨ��ֵ��׽������x�ͱ���y���⣬ͨ�����ò�׽
    // [&,x]: Ĭ��ͨ�����ò�׽������x���⣬ͨ��ֵ��׽
    // [&x,&x]: �Ƿ�����ʶ���������ظ���
    // [this]: ��׽��Χ���󡣼�ʹû��ʹ��this->��Ҳ������lambda���ʽ
    // �з����������
    // ��ʹ���У�Ҳ���������ڲ���������ʹ��[=],[&],��Ĭ�ϲ�׽���б���
    // ��Ӧѡ��׽��Ҫ�ı�����


    // ��C++14��ʼ��lambda���ʽ�Ĳ��������Զ��ƶ����͹��ܣ�������ʾָ��
    vector<int> Ints{11,55,101,155};
    vector<double> Doubles{11.1,55.5,101.1,155.5};

    auto isGreaterThan100 = [](auto i) { return i > 100; };

    auto it1 = find_if(Ints.begin(),Ints.end(),isGreaterThan100);
    if(it1 != Ints.end()){
        cout << "Found a value > 100 : " << *it1 << endl;
    }

    auto it2 = find_if(Doubles.begin(),Doubles.end(),
                       isGreaterThan100);
    if(it2 != Doubles.end()) {
        cout << "Found a value > 100 : " << *it2 << endl;
    }

    return 0;
}
