#include <algorithm>  
#include <iterator>  
#include <iostream>  
#include <vector>
using namespace std;

class GenByTwo{
private:
	int seed;
public:
	GenByTwo(int _seed=0) : seed(_seed){}
	int operator() () { return seed+=2; }
};

void operate(int& a) {
	cout<<a<<' ';
	a+=1;
}

int main(int argc,char* argv[]) 
{
	vector<int> v(10);
	generate(v.begin(),v.end(),GenByTwo(2));
	for_each(v.begin(),v.end(),operate);
	cout<<endl;
	// pirnt
	copy(v.begin(),v.end(),ostream_iterator<int>(cout," "));
	cout<<endl;

	system("pause");
	return 0;
}