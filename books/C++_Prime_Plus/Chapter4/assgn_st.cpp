// assgn_st.cpp -- assigning structrues

#include"iostream"
using namespace std;

struct inflatable
{
	char name[20];
	float volume;
	double price;
};

int main()
{
	inflatable bouquet={"sunflowers",0.20,12.49};
	inflatable choice;
	cout<<"bouquet: "<<bouquet.name<<" for $ ";
	cout<<bouquet.price<<endl;
	choice=bouquet;		// assign one structure to another
	cout<<"choice: "<<choice.name<<" for $ "
		<<choice.price<<endl;

	return 0;
}