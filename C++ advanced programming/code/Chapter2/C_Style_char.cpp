#include <iostream>

using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    // ����Ĵ����У�"Hello world"��һ���ַ���������(string literal
    // ��Ϊ����ַ�����ֵ����ʽд����������һ����������
    // �ַ��������������������ڴ����ڴ��ֻ�������С�ͨ��
    // ���ַ�ʽ���������������õȼ۵��ַ��������������ã�
    // ���Ż��ڴ��ʹ�á�Ҳ����˵����ʹһ������ʹ����500��
    // "Hello,world"�ַ�����������������Ҳֻ���ڴ��д���
    // һ��"Hello,world"ʵ�������ּ�����Ϊ��������(literal pooling)
    // C++��׼��ʽָ�����ַ���������������Ϊn��const char
    // �����飬

    char* ptr = "hello";
    // ptr[0] = 'a';        // Undefined behavior

    // һ�ָ���ȫ�ı��뷽����ʹ��ָ��const�ַ���ָ��
    const char* cPtr = "hello";
    // cPtr[0] = 'a';       // Error! Attempts to write to read-only memory

    // ���Դ���һ���ַ�����,���������ὲ����������ֻ�����ڴ���
    char arr[] = "hello";
    arr[0] = 'a';

    return 0;
}
