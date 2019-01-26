// writing to a file
#include"iostream"
#include"fstream"
using namespace std;

int main() {
	char automobile[50];
	int year;
	double a_price,d_price;

	ofstream outfile;
	outfile.open("carinfo.txt");

	cout<<"Enter the make and model of automobile: ";
	cin.getline(automobile,50);
	cout<<"Enter the model year: ";
	cin>>year;
	cout<<"Enter the original asking price: ";
	cin>>a_price;
	d_price=0.9*a_price;

	// display information on screen with cout
	cout<<fixed;
	cout.precision(2);
	cout.setf(ios_base::showpoint);
	cout<<"\nMake and model: "<<automobile<<endl;
	cout<<"Year: "<<year<<endl;
	cout<<"Was asking$:"<<a_price<<endl;
	cout<<"Now asking$:"<<d_price<<endl;

	// now do exact same things using outfile instead of cout
	outfile<<fixed;
	outfile.precision(2);
	outfile.setf(ios_base::showpoint);
	outfile<<"Make and model: "<<automobile<<endl;
	outfile<<"Year: "<<year<<endl;
	outfile<<"Was asking$:"<<a_price<<endl;
	outfile<<"Now asking$:"<<d_price<<endl;
	return 0;
}