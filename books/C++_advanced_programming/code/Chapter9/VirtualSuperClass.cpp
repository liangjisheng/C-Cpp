#include <iostream>

using namespace std;

// 如果不使用virtual关键字，用DogBird对象调用sleep()会产生歧义
// 从而导致编译器错误，因为DogBird有Animal类的两个子对象，
// 一个来自Dog，另外一个来自Bird，然而，如果Animal被作为虚基类
// DogBird就只有Animal的一个子对象，因此调用sleep()也就没有歧义

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
