#include"iostream"
#include"algorithm"
#include"vector"
#include"functional"
using namespace std;

class Print {
public:
	void operator() (int val) {cout<<val<<' '; }
};

int main() {
	int arr1[] = {1,2,3,4,5,6,7,8,9};
	vector<int> vec1(arr1, arr1 + sizeof arr1 / sizeof (int)) ;
	vector<int> vec2(9,0);	// 初始化为9个0
	for_each(vec2.begin(),vec2.end(),Print());
	cout<<endl;
	transform(vec1.begin(),vec1.end(),vec2.begin(),bind2nd(plus<int>(),1000));
	for_each(vec2.begin(),vec2.end(),Print());
	cout<<endl;

	vector<int> vec3(18,1);
	transform(vec1.begin(),vec1.end(),vec2.begin(),vec3.begin(),multiplies<int>());
	for_each(vec3.begin(),vec3.end(),Print());
	cout<<endl;

	system("pause");
	return 0;
}
