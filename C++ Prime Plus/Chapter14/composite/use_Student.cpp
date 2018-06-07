// use_Student.cpp -- using a composite class
#include"iostream"
#include"student.h"
using std::cin;
using std::cout;
using std::endl;

void set(Student &,int);
const int pupils=3;
const int quizzes=5;

int main() 
{
	Student ada[pupils]={ Student(quizzes),Student(quizzes),
		Student(quizzes) };
	int i;
	for(i=0;i<pupils;i++)
		set(ada[i],quizzes);
	cout<<"\nStudent List:\n";
	for(i=0;i<pupils;i++)
		cout<<ada[i].Name()<<endl;
	cout<<"\nResults:";
	for(i=0;i<pupils;i++) {
		cout<<endl<<ada[i];
		cout<<"average:"<<ada[i].Average()<<endl;
	}
	cout<<"Done\n";
	return 0;
}

void set(Student & sa,int n)
{
	cout<<"Please enter the student's name: ";
	gl(cin,sa);		// ÊäÈëÒ»ÐÐ
	cout<<"Please enter "<<n<<" quiz scores:\n";
	for(int i=0;i<n;i++)
		cin>>sa[i];
	while(cin.get()!='\n')
		continue;
}