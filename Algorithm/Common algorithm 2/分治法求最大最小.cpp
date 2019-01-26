#include"iostream"
using namespace std;
void maxmin(int a[],int left,int right,int *max,int *min)
{
	int x1,x2,y1,y2,mid;
	if((right-left)<=1){
		if(a[right]<a[left])
			*max=a[left],*min=a[right];
		else 
			*max=a[right],*min=a[left];
	}
	else{
		mid=(left+right)/2;
		maxmin(a,left,mid,&x1,&y1);
		maxmin(a,mid+1,right,&x2,&y2);
		*max=(x1>x2)?x1:x2;
		*min=(y1>y2)?y2:y1;
	}

}
//main
int main()
{
	int max,min,array[10]={1,2,3,4,5,6,7,8,9,0};
	maxmin(array,0,9,&max,&min);
	cout<<"max="<<max<<",min="<<min<<endl;
	return 0;
}