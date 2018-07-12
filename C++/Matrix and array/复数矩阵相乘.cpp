#include"iostream"
#include"cstdlib"
using namespace std;
#include"Complex.h"
#include"complex_mul_tem.h"

int main() {
	int m,n,p,i,j;
	cout<<"输入第一个矩阵的行数和列数:";
	cin>>m>>n;
	cout<<"输入第二个矩阵的列数:";
	cin>>p;
	Complex **ma,**mb,**mc;
	ma=new Complex*[n]; // 分配指向二位数组的指针
	mb=new Complex*[p];
	mc=new Complex*[p];
	// 分配内存
	for(i=0;i<n;i++)
		ma[i]=new Complex[m];
	for(i=0;i<p;i++) {
		mb[i]=new Complex[n];
		mc[i]=new Complex[m];
	}
	// 初始化并输出查看
	Complex c_num;
	cout<<"初始第一个矩阵:"<<endl;
	for(i=0;i<m;i++) {
		for(j=0;j<n;j++) {
			ma[i][j]=c_num;
			//cout<<ma[i][j];
			ma[i][j].show();
		}
		cout<<endl;
	}
	cout<<"初始第二个矩阵:"<<endl;
	for(i=0;i<n;i++) {
		for(j=0;j<p;j++) {
			mb[i][j]=c_num;
			// cout<<mb[i][j];
			mb[i][j].show();
		}
		cout<<endl;
	}
	cout<<"初始第三个矩阵:"<<endl;
	for(i=0;i<m;i++) {
		for(j=0;j<p;j++) {
			mc[i][j]=c_num;
			//cout<<mc[i][j];
			mc[i][j].show();
		}
		cout<<endl;
	}
	double re,im;
	cout<<"输入第一个复数矩阵元素的值:"<<endl;
	for(i=0;i<m;i++) {
		for(j=0;j<n;j++) {
			cin>>re>>im;
			ma[i][j].SetReal(re);
			ma[i][j].SetImag(im);
		}
	}
	cout<<"输入第二个复数矩阵元素的值:"<<endl;
	for(i=0;i<n;i++) {
		for(j=0;j<p;j++) {
			cin>>re>>im;
			mb[i][j].SetReal(re);
			mb[i][j].SetImag(im);
		}
	}
	
	cout<<"输出第一个复数矩阵元素的值:"<<endl;
	for(i=0;i<m;i++) {
		for(j=0;j<n;j++)
			ma[i][j].show();
		cout<<endl;
	}
	cout<<"输出第二个复数矩阵元素的值:"<<endl;
	for(i=0;i<n;i++) {
		for(j=0;j<p;j++)
			mb[i][j].show();
		cout<<endl;
	}

	cout<<"两个矩阵相乘所得到的结果是:"<<endl;
	matrix_mul<Complex>(ma,mb,mc,m,n,p);
	for(i=0;i<m;i++) {
		for(j=0;j<p;j++)
			mc[i][j].show();
		cout<<endl;
	}

	return 0;
}