#include"string"
#include"iostream"
using namespace std;

struct X{
private:
	int len;
	char *ptr;
public:
	int GetLen() { return len; }
	char * GetPtr() { return ptr; }
	X& Set(char *);
	X& Cat(char *);
	X& Copy(X&);
	void Print();
};

X& X::Set(char *pc) {
	len=strlen(pc);
	ptr=new char[len];
	strcpy(ptr,pc);
	return *this;
}

X& X::Cat(char * pc) {
	len+=strlen(pc);
	strcat(ptr,pc);
	return *this;
}

X& X::Copy(X& x) {
	Set(x.GetPtr());
	return *this;
}

void X::Print() { cout<<ptr<<endl; }

int main()
{
	X xobj1;
	xobj1.Set("abcd").Cat("efgh");
	xobj1.Print();

	X xobj2;
	xobj2.Copy(xobj1).Cat("ijkl");
	xobj2.Print();

	system("pause");
	return 0;
}