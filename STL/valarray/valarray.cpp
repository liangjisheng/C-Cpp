#include"iostream"
#include"valarray"
#include"cmath"
using namespace std;
//valarray重载了=和[]
//shift(n)以及cshift(n) 如果n>=0，向左移动valarray中的值n个位置，如果n<0,则向右移动。
//对于shift,空出的位置使用0填充；对于cshift,值按照循环的方式从一端移动到另一端
//resize(n,val) 重新初始化valarrary大小为n，每个元素的值都是val
//slice,gslice(通用化的slice),mask,indirect_array
int main()
{
	valarray<int> v;
	cout<<v.size()<<endl;
	valarray<int> v1(10);
	cout<<v1.size()<<endl;
	valarray<int> v2(3,10);
	cout<<v2.size()<<endl;
	for(int i=0;i<v2.size();i++)
		cout<<v2[i]<<" ";
	cout<<endl;
	const double a[]={1.1,2.2,3.3,4.4,5.5};
	valarray<double> v3(a,5);
	cout<<v3.size()<<endl;
	for(int j=0;j<v3.size();j++)
		cout<<v3[j]<<" ";
	cout<<endl;
	cout<<v3.sum()<<endl;
	valarray<double> v4(5);
	bool bo[]={true,false,false,true,true,false,true,false,true,true};
	for(int k=0;k<10;k++)
		cout<<bo[k]<<" ";
	cout<<endl;
	//v4=pow(v3,2);
	//cout<<v4[0]<<endl;
	//double b[]={0,1,2,3,4,5,6,7,8,9,10,11};
	v3.free();
	cout<<v3.size()<<endl;
	return 0;
}