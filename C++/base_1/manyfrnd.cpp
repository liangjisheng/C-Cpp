// manyfrnd.cpp -- unbound template friend to a template class
#include"iostream"
using std::cout;
using std::cin;
using std::endl;

template<typename T>
class ManyFriend
{
private:
	T item;
public:
	ManyFriend(const T & i) : item(i) {}
	template<typename C,typename D> friend void Show(C &,D &);
};

template<typename C,typename D> void Show(C &,D &)
{ cout<<c.item<<","<<d.item<<endl; }

int main() 
{
	ManyFriend<int> hfi1(10);
	ManyFriend<int> hfi2(20);
	ManyFriend<double> hfdb(10.5);
	cout<<"hfi1,hfi2: ";
	Show(hfi1,hfi2);
	cout<<"hfdb,hfi2: ";
	//Show(hfdb,hfi2);

	return 0;
}