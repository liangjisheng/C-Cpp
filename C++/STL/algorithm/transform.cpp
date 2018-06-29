#include"iostream"
#include"vector"
#include"algorithm"
using namespace std;

// template<class InputIterator,class OutputIterator,class UnaryOperator>
// OutputIterator transform(InputIterator first1,InputIterator last,
//							OutputIterator result,UnaryOperator op);

// template<class InputIterator1,class InputIterator2,
//			class OutputIterator2,class BinaryOperator>
// OutputIterator transform(InputIterator1 first1,InputIterator1 last1,
//							InputIterator2 first2,OutputIterator2 last2,
//							BinaryOperator binary_op);

int increase(int nScore) {
	if(nScore<60) nScore=60;
	return nScore;
}
void print(int nScore) { cout<<nScore<<' '; }

int add(int a,int b) { return a+b; }

int main()
{
	vector<int> vec;
	vec.push_back(23);
	vec.push_back(33);
	vec.push_back(43);
	vec.push_back(53);
	vec.push_back(63);
	vec.push_back(73);
	vec.push_back(83);

	cout<<"vec:"<<endl;
	for_each(vec.begin(),vec.end(),print);
	cout<<endl;

	// transform()可以在移动容器中数据的时候对数据进行操作
	// 会将increase()函数的返回值作为处理结果保存到目标容器中
	// 完成数据的移动与处理
	transform(vec.begin(),vec.end(),vec.begin(),increase);
	cout<<"After operate:"<<endl;
	for_each(vec.begin(),vec.end(),print);
	cout<<endl;

	vector<int> vec1;
	vec1.push_back(12);
	vec1.push_back(22);
	vec1.push_back(32);
	vec1.push_back(42);
	vec1.push_back(52);
	vec1.push_back(62);
	vec1.push_back(72);

	cout<<"vec1:"<<endl;
	for_each(vec1.begin(),vec1.end(),print);
	cout<<endl;

	vector<int> sum;
	sum.resize(vec.size());
	// 将vec和vec1中的对应元素相加，并将结果保存到sum中
	transform(vec.begin(),vec.end(),	// 第一个数据的范围
		vec1.begin(),					// 第二个数据的起始位置
		sum.begin(),					// 保存结果容器的起始位置
		add);							// 操作函数

	cout<<"vec+vec1:"<<endl;
	for_each(sum.begin(),sum.end(),print);
	cout<<endl;

	system("pause");
	return 0;
}