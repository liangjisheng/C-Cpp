#include"iostream.h"
#include"vector"
#include"string"
#include"algorithm"
// using namespace std;

class Rect {
public:
	double m_fw,m_fh;
public:
	Rect(double fw,double fh)
		: m_fw(fw),m_fh(fh) {}
	bool operator < (const Rect& r) {
		// 比较两个矩形的面积
		double fArea=m_fw * m_fh;
		double fOther=r.m_fw * r.m_fh;
		return fArea < fOther;
	}
	friend ostream& operator <<(ostream& os,const Rect& r);
};

ostream& operator <<(ostream& os,const Rect& r) {
	os<<"Width="<<r.m_fw<<' '<<"Heigth="<<r.m_fh; 
	return os;
}

void print(const Rect& r) { cout<<r<<endl; }

int main()
{
	using namespace std;
	vector<Rect> vecRect;
	vecRect.push_back(Rect(3,4));
	vecRect.push_back(Rect(6,7));
	vecRect.push_back(Rect(8,1));

	cout<<"Before sort:"<<endl;
	for_each(vecRect.begin(),vecRect.end(),print);
	cout<<endl;

	sort(vecRect.begin(),vecRect.end());

	cout<<"After sort:"<<endl;
	for_each(vecRect.begin(),vecRect.end(),print);
	cout<<endl;

	// Rect r(1,2);
	// cout<<r<<endl;

	system("pause");
	return 0;
}