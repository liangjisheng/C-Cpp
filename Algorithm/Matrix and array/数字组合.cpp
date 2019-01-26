// 两个整数m,n 从数列1,2,3,...,n中随意取几个数，使其和等于m,
// 要求将所有可能的组合列出来
#include"iostream"
#include"string"
using namespace std;

int mVal,nVal;
int * pOut;

void calFun(int m,int n)
{
	if(m<1 || n<1 || (n==1 && m!=1) )
		return ;
	// 看是否与所剩容积相等
	if(m==n) {
		pOut[n]=1;
		for(int i=1;i<=nVal;i++) {
			if(pOut[i])
				cout<<i<<' ';
		}
		cout<<endl;
		pOut[n]=0;
	}

	calFun(m,n-1);		// 不取n
	pOut[n]=1;
	calFun(m-n,n-1);	// 取n
	pOut[n]=0;
}

int main()
{
	cout<<"m,n:";
	cin>>mVal>>nVal;
	if(mVal<nVal) nVal=mVal;
	pOut=new int[nVal+1];
	memset(pOut,0,(nVal+1)*sizeof(int));

	calFun(mVal,nVal);
	delete []pOut;

	system("pause");
	return 0;
}