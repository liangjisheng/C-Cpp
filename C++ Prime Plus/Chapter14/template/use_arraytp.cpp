// use_arraytp.cpp -- makeing 2-d array
#include"iostream"
#include"arraytp.h"

int main() 
{
	using std::cout;
	using std::cin;
	using std::endl;
	ArrayTP<int,10> sums;
	ArrayTP<double,10> aves;
	ArrayTP< ArrayTP<int,5>,10> twodee;
	int i,j;

	for(i=0;i<10;i++) {
		sums[i]=0;
		for(j=0;j<5;j++) {
			twodee[i][j]=(i+1)*(j+1);
			sums[i]+=twodee[i][j];
		}
		aves[i]=(double)sums[i]/5;
	}

	cout<<"twodee:"<<endl;
	for(i=0;i<10;i++) {
		for(j=0;j<5;j++){
			cout.width(5);
			cout<<twodee[i][j];
		}
		cout<<" : sum=";
		cout.width(5);
		cout<<sums[i]<<",average = "<<aves[i]<<endl;
	}

	cout<<"Bye!\n";
	return 0;
}