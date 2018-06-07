#include"iostream"
using namespace std;
const int Fave=27;

int main() {
	int n;
	cout<<"Enter a number int the range 1-100 to find.\n";
	cout<<"my favorite number is:";
	cin>>n;
	while(n!=Fave) {
		if(n<Fave) cout<<"Too low...guess again:";
		else cout<<"Too high...guess again:";
		cin>>n;
	}
	cout<<"Fave is:"<<n<<endl;

	return 0;
}