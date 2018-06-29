#include"iostream"
#include"vector"
using namespace std;

void print(vector<int>);
void out(vector<int>);
void out_enhance(vector<int>);

int main()
{
	vector<int> array;
	array.push_back(1);
	array.push_back(6);
	array.push_back(6);
	array.push_back(3);
	cout<<"删除6之前:";
	print(array);

	// 删除数组中所有的6
	// out(array);
	// out_enhance(array);
	array.erase(remove(array.begin(),array.end(),6),array.end() );
	cout<<"删除6之后";
	print(array);

	system("pause");
	return 0;
}

void print(vector<int> vec) 
{
	vector<int>::iterator p=vec.begin();
	while(p!=vec.end())
		cout<<*p++<<' ';
	cout<<endl;
}

void out(vector<int> array)
{
	vector<int>::iterator iter;
	vector<int>::iterator iter2;
	for(iter=array.begin();iter!=array.end();iter++) {
		if(*iter==6)
			// array.erase()函数执行后会自动将iter指向下一个元素，
			// 所以第二个6没有删除
			iter2=iter,array.erase(iter2);
	}
}

void out_enhance(vector<int> vec)
{
	vector<int>::iterator iter;
	vector<int>::iterator iter2;
	for(iter=vec.begin();iter!=vec.end();iter++) {
		if(*iter==6)
			// array.erase()函数执行后会自动将iter指向下一个元素，
			// 所以第二个6没有删除，必须加上iter--
			iter2=iter,vec.erase(iter2);
		iter--;
	}
	// cout<<"删除6之后";
	// print(vec);
}