// probability of winning
#include"iostream"
using namespace std;

long double probability(unsigned,unsigned);

int main() {
	double total,choices;
	cout<<"Enter the total number of choices on the geme card\n"
		"the number of picks allowed:\n";
	while((cin>>total>>choices) && choices<=total) {
		cout<<"You have onw chance in :"
			<<probability(total,choices)
			<<" of winning.\n";
		cout<<"Next two numbers(an char to quit): ";
	}
	cout<<"Bye.\n";

	return 0;
}

long double probability(unsigned numbers,unsigned choices)
{
	long double result=1.0;
	unsigned n,p;
	for(n=numbers,p=choices;p>0;p--,n--)
		result=result*n/p;
	return result;
}