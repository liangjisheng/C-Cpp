#include"iostream"
#include"vector"
#include"iomanip"
using namespace std;

int main() {
	int i,j,k,row,col,heigh;
	cout<<"input row col and heigh:";
	cin>>row>>col>>heigh;
	vector<vector<vector<int> > > vecInt(heigh,vector<vector<int> >(row,vector<int>(col)));
	for(i=0;i<heigh;i++) {
		for(j=0;j<row;j++) {
			for(k=0;k<col;k++)
				vecInt[i][j][k]=i+j+k;
		}
	}
	cout<<"output the matrix:"<<endl;
	for(i=0;i<heigh;i++) {
		for(j=0;j<row;j++) {
			for(k=0;k<col;k++)
				cout<<setw(3)<<vecInt[i][j][k]<<':'
				<<setw(8)<<&vecInt[i][j][k];
			cout<<endl;
		}
		cout<<endl;
	}
	return 0;
}