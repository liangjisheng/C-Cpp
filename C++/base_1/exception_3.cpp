#include"iostream"
#include"stdexcept"
using namespace std;

int main() {
	try{
		exception X;
		throw(X);
	}
	catch(const exception& X)
	{ cout<<X.what()<<endl; }
	try {
		domain_error DomainError("Domain Mistake");
		throw(DomainError);
	}
	catch(const exception& X)
	{ cout<<X.what()<<endl; }
	try {
		logic_error Logic("Logic Mistake");
		throw(Logic);
	}
	catch(const exception& X) 
	{ cout<<X.what()<<endl; }

	return 0;
}