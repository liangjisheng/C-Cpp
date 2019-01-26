// tempmemb1.cpp -- template members
#include"iostream"
using std::cout;
using std::endl;

template<typename T>
class beta {
private:
	template<typename V>
	class hold;
	hold<T> q;
	hold<int> n;
public:
	beta(T t,int i) : q(t),n(i) {}
	template<typename U>
	U blab(U u,T t);
	void Show() const { q.Show(),n.Show(); }
};

template<typename T>
	template <typename V>
	class beta<T>::hold {
	private:
		V val;
	public:
		hold(V v=0) : val(v) {}
		void Show() const { cout<<val<<endl; }
		V value() { return val; }
	};

template<typename T>
	template<typename U>
	U beta<T>::blab(U u,T t) 
	{ return (q.value()+n.value())* u / t ; }

int main() 
{
	beta<double> guy(10.0,4);
	guy.Show();
	cout<<guy.blab(10,4)<<endl;
	return 0;
}