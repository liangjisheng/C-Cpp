// twoswap.cpp -- specialization overrides a template
#include"iostream"
using namespace std;

template <class T> 
void Swap(T& a,T& b);

struct job{
	char name[40];
	double salary;
	int floor;
};

// explicit specialization
template <>
void Swap<job> (job& j1,job& j2);

void Show(job& j);

int main() {
	cout.precision(2);
	cout.setf(ios::fixed,ios::floatfield);
	int i=10,j=20;
	cout<<"i="<<i<<",j="<<j<<endl;
	Swap(i,j);
	cout<<"Now: i="<<i<<",j="<<j<<endl;

	job sue={"lishuyu",12.34,7};
	job sid={"sid",23.45,6};
	cout<<"Before job swapping:\n";
	Show(sue);
	Show(sid);
	Swap(sue,sid);
	cout<<"After job swapping:\n";
	Show(sue);
	Show(sid);

	return 0;
}

template <class T>
void Swap(T& a,T& b) 
{
	T temp;
	temp=a,a=b,b=temp;
}

template <> 
void Swap<job>(job& j1,job& j2)
{
	double t1;
	int t2;
	t1=j1.salary,j1.salary=j2.salary,j2.salary=t1;
	t2=j1.floor,j1.floor=j2.floor,j2.floor=t2;
}

void Show(job& j)
{
	cout<<j.name<<": $"<<j.salary
		<<" on floor "<<j.floor<<endl;
}
