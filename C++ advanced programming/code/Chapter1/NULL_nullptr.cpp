#include <iostream>

using namespace std;

void func(char* str){
    cout<<"char* version"<<endl;
}

void func(int i){
    cout<<"int version"<<endl;
}

int main()
{
    // NULL����ָ�룬���ȼ�������0������ʵ�ʵ��õ���func()�������汾��
    func(NULL);

    // nullptr �������Ŀ�ָ�볣��,��������func()��char*�汾
    func(nullptr);

    return 0;
}
