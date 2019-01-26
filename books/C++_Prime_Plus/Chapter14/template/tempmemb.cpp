// tempmemb.cpp -- template members
#include"iostream"
using std::cout;
using std::endl;

template<typename T>
class beta {
private:
	template<typename V>
	class hold {
	private:
		V val;
	public:
		hold(V v=0) : val(v) {}
		void Show() const { cout<<val<<endl; }
		V value() const { return val; }
	};
	hold<T> q;
	hold<int> n;
public:
	beta(T t,int i) : q(t),n(i) {}
	template<typename U>
	U blab(U u,T t) { return (n.value()+q.value())*u/t; }
	void Show() const { q.Show(),n.Show(); }
};

int main() 
{
	beta<double> guy(3.5,3);
	guy.Show();
	cout<<guy.blab(10,2.3)<<endl;
	cout<<"Done\n";

	return 0;
}