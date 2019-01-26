#include"iostream"
#include"iomanip"
#include"vector"
using namespace std;

int main() {
	int row,col,i,j;
	cout<<"input row and col:";
	cin>>row>>col;
	vector<vector<int> > vecInt(row,vector<int>(col));
	cout<<"input matrix element:"<<endl;
	for(i=0;i<row;i++) {
		for(j=0;j<col;j++)
			cin>>vecInt[i][j];
	}
	cout<<"output matrix element:"<<endl;
	for(i=0;i<row;i++) {
		for(j=0;j<col;j++)
			cout<<setw(3)<<vecInt[i][j]<<':'
			<<setw(8)<<&vecInt[i][j];
		cout<<endl;
	}
	return 0;
}