#include <iostream>
#include <vector>

using namespace std;

class MoveableClass
{
public:
    MoveableClass(){
        cout << "Default constructor" << endl;
    }
    MoveableClass(const MoveableClass& src){
        cout << "Copy constructor" << endl;
    }
    MoveableClass(MoveableClass&& src) noexcept {
        cout << "Move constructor" << endl;
    }
    MoveableClass& operator=(const MoveableClass& rhs){
        cout << "Copy assignment operator" << endl;
        return *this;
    }
    MoveableClass& operator=(MoveableClass&& rhs) noexcept {
        cout << "Move assignment operator" << endl;
        return *this;
    }
    virtual ~MoveableClass(){
        cout << "deconstructor" << endl;
    }
};


int main()
{
    vector<MoveableClass> vec;
    MoveableClass mc;

    // ��vec�пռ䲻���ǣ�����������ڴ棬��ԭ����ʹ��
    // �ƶ����ƹ��캯���ƶ����µĿռ���
    vec.push_back(mc);
    vec.push_back(mc);
    //vec.push_back(mc);
    //vec.push_back(mc);
    cout << endl;

    // ʹ���ƶ����Ʋ�����֮�󣬲������ڷ���vec�е�Ԫ��
    // vec�е�Ԫ�ػ��Զ�������������
    vector<MoveableClass> vec1(make_move_iterator(vec.begin()),
                               make_move_iterator(vec.end()));

    cout << endl;

    return 0;
}
