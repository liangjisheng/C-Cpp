#include"iostream"
using namespace std;
#include"vector"
int main(int argc,char *argv[])
{
	vector< vector<double> > a(3,vector<double>(5,8));
	a.push_back(vector<double>(5,7));
	int i,j;
	for(i=0;i<a.size();i++)
		a[i].push_back(0);
	for(int row=0;row<a.size();row++){
		for(int col=0;col<a[row].size();col++)
			cout<<a[row][col]<<"\t";
		cout<<endl;
	}
	vector< vector<double> > atable;
	for(i=1;i<=3;i++)
		atable.push_back(vector<double>(i,4));
	for(i=0;i<atable.size();i++){
		for(j=0;j<atable[i].size();j++)
			cout<<atable[i][j]<<"\t";
		cout<<endl;
	}
	return 0;
}