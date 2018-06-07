// twotemps.cpp -- using overloaded template functions
#include"iostream"
using namespace std;

template <class T>
void Swap(T& a,T& b);

template <class T>
void Swap(T* a,T* b,int n);

template <class T>
void Show(T a[],int n);

const int Lim=8;

int main()
{
	int i=10,j=20;
	cout<<"i="<<i<<",j="<<j<<endl;
	Swap(i,j);
	cout<<"Now i="<<i<<",j="<<j<<endl;
	
	double arr1[]={0,1,2,3,4,5,6,7};
	double arr2[]={7,6,5,4,3,2,1,9};
	Show(arr1,Lim);
	Show(arr2,Lim);
	Swap(arr1,arr2,Lim);
	cout<<"Swapped arrays:\n";
	Show(arr1,Lim);
	Show(arr2,Lim);
	return 0;
}

template <class T>
void Swap(T& a,T& b)
{
	T temp;
	temp=a,a=b,b=temp;
}

template <class T>
void Swap(T* a,T* b,int n)
{
	T temp;
	int i;
	for(i=0;i<n;i++)
		temp=a[i],a[i]=b[i],b[i]=temp;
}

template <class T>
void Show(T a[],int n)
{
	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
	cout<<endl;
}