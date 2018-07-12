// 中国象棋的将帅问题，两个棋子可以放到那些位置
// 用3*3的矩阵表示可以走的位置，初始化为1-9
#include"iostream"
using namespace std;

int main() {
	int a[3][3],b[3][3],i,j,m,n,num=1;
	for(i=0;i<3;i++) {		// 初始化
		for(j=0;j<3;j++) {
			a[i][j]=num;
			b[i][j]=num;
			num++;
		}
	}
	int count=0;
	for(i=0;i<3;i++) {
		for(j=0;j<3;j++) {
			for(m=0;m<3;m++) {
				for(n=0;n<3;n++) {
					if(j!=n) {
						cout<<"A="<<a[i][j]<<",B="<<b[m][n]<<"  ";
						count++;
						if(count%5==0) cout<<endl;
					}
				}
			}
		}
	}
	cout<<endl;
	return 0;
}