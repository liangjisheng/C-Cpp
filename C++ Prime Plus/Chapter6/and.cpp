#include"iostream"
using namespace std;
const int ArSize=6;

int main() {
	float naaq[ArSize];
	cout<<"Enter the NAAQs(New Age AWARENESS Quotients)"
		"of\nyour neighbors.Program termiantes "
		"when you make\n"<<ArSize<<" entries"
		"or enter a negetive value.\n";

	int i=0;
	float temp;
	cout<<"First value:";
	cin>>temp;
	while(i<ArSize && temp>=0) {
		naaq[i]=temp;
		i++;
		cout<<"Input next value:";
		cin>>temp;
	}
	if(i==0)
		cout<<"No data-bye\n";
	else {
		cout<<"Enter you NAAQ:";
		float you;
		cin>>you;
		int count=0;
		for(int j=0;j<i;j++)
			if(naaq[j]>you) count++;
		cout<<count;
		cout<<" of your neighbors have greater awareness of\n"
			"the New Age than you do.\n";

	}

	return 0;
}