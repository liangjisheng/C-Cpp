#include"iostream"
using namespace std;
class Data{
private:
	int x,y;
public:
	const int data;
	Data(int a=0,int b=0,int d=0):x(a),y(b),data(d){}
	int getx()const{return x;}
	int gety()const{return y;}
	void show()const{cout<<"x="<<x<<",y="<<y<<",data="<<data<<endl;}
};
int main(int argc,char*argv[])
{
	Data d;
	const Data d1;
	d1.show();
	const Data d2(10,20,30);
	d2.show();
	Data *const p=&d;
	p->show();
	const Data *p2=&d2;
	p2->show();
	const Data *p1=&d1;
	p1->show();
	const Data &r1=d1;
	r1.show();
	const Data &r2=d2;
	r2.show();
	return 0;
}