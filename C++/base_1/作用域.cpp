#include"iostream"
using namespace std;
int k=10;
class Windows{
public:
	void set1(int w){this->w=w;}
	void set2(int w){Windows::w=w;}
	void set3(int d){k=d;}
	void set4(int e){::k=e;}
	int h,w,k;
};
int main(int argc,char *argv[])
{
	Windows win;
	cout<<"extern k="<<k<<endl;
	win.set1(4);cout<<"win.w="<<win.w<<endl;
	win.set2(5);cout<<"win.w="<<win.w<<endl;
	win.set3(6);cout<<"win.w="<<win.w<<endl;
	win.set4(7);cout<<"extern k="<<k<<endl;
	return 0;
}