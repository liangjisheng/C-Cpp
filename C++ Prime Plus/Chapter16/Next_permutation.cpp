// Next_permutation.cpp -- apply the STL to a string
#include"string"
#include"iostream"
#include"algorithm"

int main()
{
	using namespace std;
	string str;
	cout<<"Enter a string(quit to quit): ";
	while(cin>>str && str!="quit") {
		cout<<"Permutations of "<<str<<endl;
		sort(str.begin(),str.end());
		cout<<str<<endl;
		// next_permutation()算法将区间转换为下一种排列方式
		// 若成功 return true,否则 return false 直到最后的排列方式
		// 且自动提供唯一的排列方式
		while(next_permutation(str.begin(),str.end()))
			cout<<str<<endl;
		cout<<"Enter a string(quit to quit): ";
	}

	cout<<"Bye!\n";
	return 0;
}