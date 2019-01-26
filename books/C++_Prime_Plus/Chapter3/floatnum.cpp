// float.cpp -- float-point types
#include"iostream"
using namespace std;

int main() {
	cout.setf(ios_base::fixed,ios_base::floatfield);	// fixed-point
	float tub=10.0/3.0;	 // good to about 6 places
	double mint=10.0/3.0;	 // good to about 15 palces
	const float million=1.0e6;
	cout<<"tub= "<<tub
		<<", a million tubs = "<<million*tub
		<<"\nand ten million tubs= "
		<<10*million*tub<<endl;

	cout<<"mint= "<<mint<<" and a million mints= "
		<<million* mint<<endl;

	return 0;
}