#include"iostream"
#include"ctime"
#define size 10
using namespace std;
//quicksort
void quicksort(int a[],int n,int left,int right)
{
	int i,j,t;
	if(left<right){
		i=left;j=right+1;
		while(1){
			while(i+1<n&&a[++i]<a[left]);        //后移
			while(j-1>-1&&a[--j]>a[left]);       //前移
			if(i>=j)break;
			t=a[i],a[i]=a[j],a[j]=t;
		}
		t=a[left],a[left]=a[j],a[j]=t;            //交换
		quicksort(a,n,left,j-1);
		quicksort(a,n,j+1,right);
	}
}
//main
void main()
{
	int list[size],i;
	srand(time(0));
	cout<<"Output the list:"<<endl;
	for(i=0;i<size;i++){              //随机生成数组
		list[i]=rand()%10+100;
		cout<<list[i]<<",";
	}
	cout<<endl;

	quicksort(list,size,0,size-1);    //快速排序及结果输出
	cout<<"sorting result:"<<endl;
	for(i=0;i<size;i++)
		cout<<list[i]<<",";
	cout<<endl;

	int num[size][2],j;               //定义记录数组
	for(i=0;i<size;i++)               //初始化为0
		for(j=0;j<2;j++)
			num[i][j]=0;

	j=0;                              //开始数字统计，此时已排好序
	num[j][0]=list[0];num[j][1]=1;
	for(i=1;i<size;i++){
		if(list[i]==num[j][0])num[j][1]++;
		else{
			num[++j][0]=list[i];
			num[j][1]++;
		}
	}
	int row=j;                         //记录有多少行数字
	cout<<"output the number staticis:"<<endl;    //输出统计结果
	for(i=0;i<=row;i++){
		for(j=0;j<2;j++){
			if(num[i][j]!=0)
				cout<<num[i][j]<<" ";
		}
		cout<<endl;
	}
}