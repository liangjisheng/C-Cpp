#include"iostream"
#include"iomanip"
using namespace std;

int main() {
	int row,col,i,j;
	cout<<"input row and col number:";
	cin>>row>>col;
	int **p=new int*[row];
	for(i=0;i<row;i++)
		p[i]=new int[col];
	cout<<"input matrix elements:"<<endl;
	for(i=0;i<row;i++) {
		for(j=0;j<col;j++)
			cin>>p[i][j];
	}
	cout<<"output matrix elements:"<<endl;
	for(i=0;i<row;i++) {
		for(j=0;j<col;j++)
			cout<<setw(4)<<p[i][j]<<':'<<setw(8)<<&p[i][j];
		cout<<endl;
	}
	// delete 
	for(i=0;i<row;i++)
		delete [] p[i];
	delete []p;
	return 0;
}