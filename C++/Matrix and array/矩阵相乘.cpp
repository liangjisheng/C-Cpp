// 求两个矩阵相乘

#include"iostream"
#include"cstdlib"
using namespace std;

//template<class T>
void matrix_mul(double *ma,double *mb,double *mc,int &m,int &n,int &p)
{
	int i,j,k;
	for(i=0;i<m;i++) {
		for(j=0;j<p;j++) {
			for(k=0;k<n;k++)
				//*(mc+i*p+j) += (*(ma+i*n+k)) * (*(mb+k*p+j));
				// 上一行代码与下面的代码等价，知道起始地址操作后面分配好的地址
				mc[i*p+j] += ma[i*n+k] * mb[k*p+j];
		}
	}
}

int main() {
	cout<<"此程序用于求两个矩阵相乘:"<<endl;
	int m,n,p,i,j;
	double *ma,*mb,*mc;
	cout<<"输入第一个矩阵的行数和列数:";
	cin>>m>>n;
	cout<<"输入第二个矩阵的列数:";
	cin>>p;
	ma=(double*)malloc(m*n*sizeof(double));
	mb=(double*)malloc(n*p*sizeof(double));
	mc=(double*)malloc(m*p*sizeof(double));
	for(i=0;i<m;i++) {
		for(j=0;j<p;j++)
			//*(mc+i*m+j)=0;
			// 上下两行带代码等价
			mc[i*m+j]=0.0;
	}

	cout<<"输入第一个矩阵的元素值:"<<endl;
	for(i=0;i<m;i++) {
		for(j=0;j<n;j++)
			cin>>*(ma+i*m+j);
	}
	cout<<"输入第二个矩阵的元素值:"<<endl;
	for(i=0;i<n;i++) {
		for(j=0;j<p;j++)
			cin>>*(mb+i*n+j);
		// 在输入时，这一行与上一行不等价，必须使用上一行的格式
		//cin>>ma[i*n+j]; 
	}
	
	cout<<"输出第一个矩阵的元素值:"<<endl;
	for(i=0;i<m;i++) {
		for(j=0;j<n;j++)
			//cout<<*(ma+i*m+j)<<" ";  //这一行这样写和下面一行等价
			cout<<ma[i*m+j]<<" ";
		cout<<endl;
	}
	
	cout<<"输出第二个矩阵的值:"<<endl;
	for(i=0;i<n;i++) {
		for(j=0;j<p;j++)
			cout<<*(mb+i*n+j)<<" ";
		cout<<endl;
	}

	matrix_mul(ma,mb,mc,m,n,p);

	cout<<"相乘所得矩阵为:"<<endl;
	for(i=0;i<m;i++) {
		for(j=0;j<p;j++)
			cout<<*(mc+i*m+j)<<" ";
		cout<<endl;
	}
	
	free(ma);
	free(mb);
	free(mc);

	return 0;
}