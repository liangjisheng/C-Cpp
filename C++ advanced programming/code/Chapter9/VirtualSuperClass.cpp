#include <iostream>

using namespace std;

// �����ʹ��virtual�ؼ��֣���DogBird�������sleep()���������
// �Ӷ����±�����������ΪDogBird��Animal��������Ӷ���
// һ������Dog������һ������Bird��Ȼ�������Animal����Ϊ�����
// DogBird��ֻ��Animal��һ���Ӷ�����˵���sleep()Ҳ��û������

class Animal{
public:
    virtual void eat() = 0;
    virtual void sleep() { cout << "zzzzz....." << endl; }
};

class Dog : public virtual Animal{
public:
    virtual void bark() { cout << "Woof" << endl; }
    virtual void eat() override { cout << "The dog has eaten" << endl;}
};

class Bird : public virtual Animal{
public:
    virtual void chirp() { cout << "Chirp" << endl; }
    virtual void eat() override { cout << "The bird has eaten." << endl; }
};

class DogBird : public Dog,public Bird {
public:
    virtual void eat() override { Dog::eat(); }
};

int main()
{
    DogBird myConfuseAnimal;
    myConfuseAnimal.sleep();    // Not ambiguous because Animal is virtual
    myConfuseAnimal.eat();

    return 0;
}
