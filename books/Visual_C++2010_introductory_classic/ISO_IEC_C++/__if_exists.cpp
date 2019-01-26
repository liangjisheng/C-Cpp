// the__if_exists_statement.cpp
// compile with : /EHsc
#include <iostream>

template<typename T>
class X : public T {
public:
	void Dump() {
		std::cout<<"In X<T>::Dump()."<<std::endl;

		__if_exists(T::Dump) {
			T::Dump();
		}

		__if_not_exists(T::Dump) {
			std::cout<<"T::Dump does not exist"<<std::endl;
		}
	}
};

class A {
public:
	void Dump() {
		std::cout<<"In A::Dump()"<<std::endl;
	}
};

class B {};

bool g_bFlag = true;

class C {
public:
	void f(int);
	void f(double);
};

int main() {
	X<A> x1;
	X<B> x2;

	x1.Dump();
	x2.Dump();

	__if_exists(::g_bFlag) {
		std::cout<<"g_bFlag = "<< g_bFlag << std::endl;
	}

	__if_exists(C::f) {
		std::cout << "C::f exists" << std::endl;
	}

	system("pause");
	return 0;
}