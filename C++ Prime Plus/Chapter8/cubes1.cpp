// cubes.cpp -- regular and reference arguments
#include"iostream"
using namespace std;
double cube(double);
double refcube(double &);

int main() {
	double x=3;
	cout<<cube(x)<<" =cube of "<<x<<endl;
	cout<<refcube(x)<<" =refcube of "<<x<<endl;

	return 0;
}

double cube(double a) {
	a*= a*a;
	return a;
}

double refcube(double & ra) {
	ra*= ra*ra;
	return ra;
}