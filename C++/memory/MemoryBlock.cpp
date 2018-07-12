#include"iostream"
#include"algorithm"
using namespace std;

// 一个管理内存资源的类
class MemoryBlock {
private:
	int _length;
	int* _data;
public:
	// constructor
	MemoryBlock(size_t length)
		: _length(length), _data(new int[length]) 
	{
		cout<<"创建对象，长度="<<_length<<",申请资源"<<endl;
	}
	// destructor
	~MemoryBlock() {
		cout<<"销毁对象，长度="<<_length<<",";
		if(_data!=NULL) {
			cout<<"释放资源";
			delete [] _data;
		}
		cout<<endl;
	}
	// copy_constructor
	MemoryBlock(const MemoryBlock& other)
		:_length(other._length),_data(new int[other._length])
	{
		cout<<"复制构造函数 长度="<<other._length
			<<",申请资源并复制到目标资源"<<endl;
		// 复制源对象的内存资源到目标对象的内存资源
		copy(other._data,other._data+_length,_data);
	}
	// 普通的复制操作符=，接收一个左值引用为参数
	MemoryBlock& operator=(const MemoryBlock& other)
	{
		if(this!=&other) {
			cout<<"赋值操作符。长度="<<other._length
				<<",释放已有资源。重新申请资源"
				<<"并复制资源到目标资源"<<endl;
			delete [] _data;
			_length=other._length;
			_data=new int[_length];
			copy(other._data,other._data+_length,_data);
		}
		return *this;
	}
	// 获取内存长度
	size_t Length() const { return _length; }
};

int main()
{
	MemoryBlock a(3),b(6);
	swap(a,b);

	system("pause");
	return 0;
}

// swap()算法的具体实现
// template<class T> void swap(T& a,T& b)
// {
// 	T tmp(move(a));	// 对象a被复制到对象tmp
//	a=move(b);		// 对象b被复制到对象a
//	b=move(tmp);	// 对象tmp被复制到对象b
// }
// 标准库中的move()函数来获取对象的右值引用