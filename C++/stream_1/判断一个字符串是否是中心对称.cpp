#include"iostream"
#include"cstring"
using namespace std;
int main()
{
	char a[100];
	cout<<"Please input a string:";
	cin>>a;
	int len=strlen(a);
	int mid;
	if(len%2==0)mid=len/2;
	else mid=len/2+1;
	while(mid<len){
		if(a[mid]==a[len-mid-1])mid++;
		else {mid=0;break;}
	}
	if(mid)cout<<"中心对称."<<endl;
	else cout<<"中心不对称."<<endl;
	return 0;
}