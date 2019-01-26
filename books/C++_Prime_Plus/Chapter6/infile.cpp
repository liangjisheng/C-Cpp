// sumafile -- function with an array argument
#include"iostream"
#include"fstream"
#include"cstdlib"
using namespace std;
const int SIZE=60;

int main() {
	char filename[SIZE];
	ifstream infile;

	cout<<"Enter name of data file: ";
	//cin>>filename;
	cin.getline(filename,SIZE);
	infile.open(filename);
	if(!infile.is_open()) {
		cout<<"Could not open the file"<<filename<<endl;
		cout<<"Program terminating.\n";
		exit(EXIT_FAILURE);
	}
	double value,sum=0.0;
	int count=0;
	while(infile>>value) {			// !infile.eof()
									// infile>>value; 换成这两句话效果一样
		count++;					
		sum+=value;
	}
	if(infile.eof())
		cout<<"End of file reached.\n";
	else if(infile.fail())
		cout<<"Input terminated by data mismatch.\n";
	else
		cout<<"Input terminated for unknow reason.\n";

	if(count==0)
		cout<<"No data processed.\n";
	else {
		cout<<"Items read: "<<count<<endl;
		cout<<"Sum: "<<sum<<endl;
		cout<<"Average: "<<sum/count<<endl;
	}
	infile.close();
	return 0;
}