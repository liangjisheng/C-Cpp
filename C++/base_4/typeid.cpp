
#include<iostream>
#include<typeinfo>

using namespace std;

struct Base {};
struct Derived : Base {};
// 有了虚函数之后，会动态绑定，在运行时才进行类型检查，
// 如果没有虚函数，则会在编译是进行类型检查
struct Poly_Base { virtual void Member() {} };
struct Poly_Derived : Poly_Base {};

int main()
{
	// build-in types:
	int i = 0;
	int *pi = &i;
	cout << "int is: " << typeid(int).name() << endl;
	cout << "  i is: " << typeid(i).name() << endl;
	cout << " pi is: " << typeid(pi).name() << endl;
	cout << "*pi is: " << typeid(*pi).name() << endl;

	// non-polymorphic types:
	Derived derived;
	Base *pBase = &derived;
	cout << "derived is: " << typeid(derived).name() << endl;
	cout << " *pBase is: " << typeid(*pBase).name() << endl;
	cout << boolalpha << "same type ? ";
	cout << (typeid(derived) == typeid(*pBase)) << endl << endl;

	// polymorphic types:
	Poly_Derived polyderived;
	Poly_Base *pPolyBase = &polyderived;
	cout << "polyderived is: " << typeid(polyderived).name() << endl;
	cout << " *ppolybase is: " << typeid(*pPolyBase).name() << endl;
	cout << boolalpha << "same type ? ";
	cout << (typeid(polyderived) == typeid(*pPolyBase)) << endl << endl;

	cout << typeid(int).hash_code() << endl;
	cout << typeid(int).raw_name() << endl;
	cout << typeid(int).name() << endl;

	system("pause");
	return 0;
}