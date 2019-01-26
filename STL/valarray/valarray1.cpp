// valarray.cpp 
#include"iostream"
#include"valarray"
#include"iomanip"
#include"cmath"

int main()
{
	using namespace std;
	double pi=3.14159265358;
	int i;
	valarray<double> v1(9);
	valarray<double> v2(9);
	for(i=0;i<9;i++)
		v1[i]=0.25*i-1;
	cout<<"The initial valarray is:";
   for (i=0;i<9;i++)
      cout<<" "<<v1[i];
   cout<<endl;

   v2=acos(v1);		// valarray 可以直接对数组进行操作，
   for(i=0;i<9;i++) {
	   cout<<setw(10)<<v2[i]<<' ';
	   if(i==4)
		   cout<<endl;
   }
   cout<<endl;

   cout<<"max(v1)="<<v1.max()<<endl;
   cout<<"min(v1)="<<v1.min()<<endl;
   cout<<"sum(v1)="<<v1.sum()<<endl;
   // cshift将valarray数组的数据进行循环移动，参数为正者左移为负就右移
   //shift将valarray数组移动，参数为正者左移，为负者右移，移动后由0填充剩余位
   cout<<"v1:\n";
	v1.shift(3);
	for(i=0;i<9;i++) {
	   cout<<setw(10)<<v1[i]<<' ';
	   if(i==4)
		   cout<<endl;
   }
   cout<<endl;

   system("pause");
   return 0;
}
