#include <iostream> 
#include <ctime> 
using namespace std; 

int max(int x,int y) { return (x>y)?x:y; } 

int main() { 
	const double begin=(double)clock()/CLK_TCK; 
	for(int i=10000;i>0;i--) 
		for(int j=10000;j>0;j--) 
			max(i,j); 
	const double end=(double)clock()/CLK_TCK; 
	cout <<begin<<" "<<end; 
	cout<<endl;

	return 0; 
}