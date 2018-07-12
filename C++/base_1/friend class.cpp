#include"iostream"
using namespace std;
#ifndef DATA
#define DATA
class CSquare;
class CRectangle{
public:
	int area()
	{return width*height;}
	void convert(CSquare a);
private:
	int width,height;
};
class CSquare{
private:
	int side;
public:
	void set_side(int a){side=a;}
	friend class CRectangle;
};
void CRectangle::convert(CSquare a)
{width=a.side;height=a.side;}
#endif
//main
int main()
{
	CSquare sqr;
	CRectangle rect;
	sqr.set_side(4);
	rect.convert(sqr);
	cout<<rect.area()<<endl;
	return 0;
}