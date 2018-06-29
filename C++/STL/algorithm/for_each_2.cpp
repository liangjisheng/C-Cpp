#include <iostream>
#include"vector"
#include"algorithm"
using namespace std;
// run this program using the console pauser or add your own getch, system("pause") or input loop
void addSalary(int& nSalary) {
	if(nSalary<2000)
	nSalary*=1.3;
}
void print(int& a)
{ cout<<a<<' '; }

int main(int argc, char** argv) {
	vector<int> vec;
	vec.push_back(3200);
	vec.push_back(1200);
	vec.push_back(2200);
	vec.push_back(1800);
	for_each(vec.begin(),vec.end(),addSalary);
	for_each(vec.begin(),vec.end(),print);
	cout<<endl;
	
	system("pause");
	return 0;
}
