// label_with_goto.cpp
// compile with :/EHsc
#include <iostream>

int main() {
	using std::cout;
	using std::endl;
	using std::cerr;
	goto Test2;

	cout<<"testing"<<endl;

Test2 :
	cerr<<"At Test2 label."<<endl;

	system("pause");
	return 0;
}