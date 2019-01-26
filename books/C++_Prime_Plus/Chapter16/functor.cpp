// functor.cpp -- using a functor
#include"iostream"
#include"list"
#include"iterator"

template<class T>
class TooBig{
private:
	T cutoff;
public:
	TooBig(const T & t=50) : cutoff(t) {}
	bool operator() (const T & v) { return v>cutoff; }
};

int main()
{
	using namespace std;
	TooBig<int> f100(100);
	list<int> L1;
	list<int> L2;
	int vals[10]={50,100,90,180,60,210,415,88,188,201};

	L1.insert(L1.begin(),vals,vals+10);
	L2.insert(L2.begin(),vals,vals+10);
	std::ostream_iterator<int,char> out(cout," ");
	cout<<"Original lists:\n";
	copy(L1.begin(),L1.end(),out);
	cout<<endl;
	copy(L2.begin(),L2.end(),out);
	cout<<endl;
	L1.remove_if(f100);		// use a named function object
	L2.remove_if(TooBig<int>(200));	// constructor a function object
	cout<<"Trimmed lists: \n";
	copy(L1.begin(),L1.end(),out);
	cout<<endl;
	copy(L2.begin(),L2.end(),out);
	cout<<endl;

	return 0;
}