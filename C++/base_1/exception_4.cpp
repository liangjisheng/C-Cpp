#include"iostream"
using namespace std;
#include"vector"
int main(int argc,char* argv[])
{
	vector<int> v(4,99);
	try{
		for(int i=0;i<5;i++)
			cout<<v.at(i)<<endl;
	}
	catch(out_of_range exception)
	{
		cout<<"Exception occurred: "
			<<exception.what()<<endl;
	}
	return 0;
}