// binary.cpp -- binary file I/O
#include"iostream"
#include"fstream"
#include"iomanip"
#include"cstdlib"
#include"cstring"
inline void eatline() { while(std::cin.get()!='\n') continue; }

struct planet {
	char name[20];		// name of planet
	double population;	// its population
	double g;	// its acceleration of gravity
};
const char * file="planets.dat";

int main()
{
	using namespace std;
	planet pl;
	cout<<fixed<<right;

	// show initial contents
	ifstream fin;
	fin.open(file,ios::in | ios::binary);
	if(fin.is_open()) {
		cout<<"Here are the current contents of the "
			<<file<<" file\n";
		while(fin.read((char*)&pl,sizeof(pl))) {
			cout<<setw(20)<<pl.name<<": "
				<<setprecision(0)<<setw(12)<<pl.population
				<<setprecision(0)<<setw(6)<<pl.g<<endl;
		}
		fin.close();
	}

	// add new data
	ofstream fout;
	fout.open(file,ios::out | ios::app | ios::binary);
	if(!fout.is_open()) {
		cerr<<"Cann't open "<<file<<" file for output:\n";
		exit(EXIT_FAILURE);
	}
	cout<<"Enter planet name(enter a blank line to quit):\n";
	cin.get(pl.name,20);
	while(strcmp(pl.name,"quit")) {
		eatline();
		cout<<"Enter population:";
		cin>>pl.population;
		cout<<"Enter acceleration of gravity: ";
		cin>>pl.g;
		eatline();
		fout.write((char*)&pl,sizeof(pl));
		cout<<"\nEnter planet name(enter a blank line to quit):\n";
		cin.get(pl.name,20);
	}
	fout.close();

	// show revised file
	fin.clear();
	fin.open(file,ios::in | ios::binary);
	if(fin.is_open()) {
		cout<<"Here are the current contents of the "
			<<file<<" file\n";
		while(fin.read((char*)&pl,sizeof(pl))) {
			cout<<setw(20)<<pl.name<<": "
				<<setprecision(0)<<setw(12)<<pl.population
				<<setprecision(0)<<setw(6)<<pl.g<<endl;
		}
		fin.close();
	}
	
	cout<<"\nBye!\n";
	system("pause");
	return 0;
}