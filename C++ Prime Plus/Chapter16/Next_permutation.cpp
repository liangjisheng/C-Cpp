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
		// next_permutation()�㷨������ת��Ϊ��һ�����з�ʽ
		// ���ɹ� return true,���� return false ֱ���������з�ʽ
		// ���Զ��ṩΨһ�����з�ʽ
		while(next_permutation(str.begin(),str.end()))
			cout<<str<<endl;
		cout<<"Enter a string(quit to quit): ";
	}

	cout<<"Bye!\n";
	return 0;
}