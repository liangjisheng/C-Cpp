#include"iostream"
#include"vector"
#include"ctime"
#include"cstdlib"
using namespace std;

template<typename T>
int Search(const vector<T> &v,T item)
{
	for(int i=0;i<v.size();i++)
		if(v[i]==item||i>=v.size())
			return i;
}

//main
int main()
{
	srand(time(0));
	vector<int> num1,num2,count;
	int n,i;
	for(i=1;i<=100;i++){
		n=rand()%5;
		num1.push_back(n);
		//cout<<n<<" ";
	}
	//cout<<endl;
	int pos;
	for(i=0;i<num1.size();i++){
		pos=Search(num2,num1[i]);
		if(pos>=num2.size()){
			num2.push_back(num1[i]);
			count.push_back(1);
		}
		else
			count[pos]++;
	}
	//vector<int>::iterator It;
	for(i=0;i<num2.size();i++)
		cout<<num2[i]<<"   "<<count[i]<<endl;
	return 0;
}