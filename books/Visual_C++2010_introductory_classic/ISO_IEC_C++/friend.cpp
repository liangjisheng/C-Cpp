// Createing a friend function of a class
#include <iostream>
using std::endl;
using std::cout;

class CBox
{
public:
	explicit CBox(double lv=1.0,double bv=1.0,double hv=1.0)
	{
		cout<<"Constructor called."<<endl;
		m_Length=lv;
		m_Width=bv;
		m_Height=hv;
	}
	double Volume()
	{
		return m_Length*m_Height*m_Width;
	}
private:
	double m_Length,m_Width,m_Height;
	friend double BoxSurface(CBox& aBox);
};

// friend function to calculate the surface area of a Box object
double BoxSurface(CBox& aBox)
{
	return 2*(aBox.m_Height*aBox.m_Width+
				aBox.m_Height*aBox.m_Length+
				aBox.m_Length*aBox.m_Width
				);
}

int main(void)
{
	CBox match(2.2,1.1,0.5);
	CBox box2;

	cout<<"\nVolume of match = "
		<<match.Volume();

	cout<<"\nVolume of box2 = "
		<<box2.Volume();

	cout<<"\nSurface area of box2 = "
		<<BoxSurface(box2)<<endl;

	system("pause");
	return 0;
}