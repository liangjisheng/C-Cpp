#include"iostream"
using namespace std;
template<class type>
class Point{
	private:
		type x,y;
	public:
		Point():x(0),y(0){}
		Point(const type a,const type b):x(a),y(b){}
		void display(){cout<<"display:"<<"x="<<x<<",y="<<y<<endl;}
};

int main(int argc,char *argv[])
{
	Point<int> dian,dian1(3,4);
	dian.display();
	dian1.display();
	return 0;
}