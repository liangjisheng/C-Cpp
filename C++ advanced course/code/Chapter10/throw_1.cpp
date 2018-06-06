
// 用throw抛出一个异常到catch子句中与通过函数调用传递一个参数，这里面有
// 一些相同点，但是他们也存在这巨大的差异
// 首先是相同点，传递函数参数与异常的途径可以是传值、传引用或传指针，这
// 是相同的，但是在传递参数与异常的过程中，系统所要完成的操作则是完全
// 不同的。产生这个差异的原因是：调用函数时，程序的控制权最终还会返回到
// 函数的调用处，但是当抛出一个异常时，控制权永远不会回到抛出异常的地方

// 看下面代码
#include <iostream>

using namespace std;

class stuff
{
	int n;
	char c;
public:
	void Addr() { cout << this << endl; }
	friend istream& operator>>(istream&, stuff&);
};

istream& operator>>(istream& in, stuff& w)
{
	w.Addr();
	cout << "input a integer and char:";
	cin >> w.n;
	cin >> w.c;
	cin.get();
	return in;
}

void passAndThrow()
{
	stuff localStuff;
	localStuff.Addr();
	cin >> localStuff;
	throw localStuff;
}

void passAndThrow_static()
{
	static stuff localStuff;
	localStuff.Addr();
	cin >> localStuff;
	throw localStuff;
}

int main()
{
	// 对异常对象进行强制复制拷贝，有助于理解参数传递与抛出异常的差异
	// 抛出异常运行速度比参数传递要慢
	
	try{
		// passAndThrow();

		// 即使抛出的对象不会被释放，也会进行拷贝操作，此时localStuff是
		// 局部静态对象，抛出异常时localStuff并不会被析构，此时仍将复制
		// 出localStuff的一个拷贝
		passAndThrow_static();
	}
	// 尽管catch子句捕捉的是异常对象的引用，但是捕捉到的异常对象已经不是
	// localStuff，而是他的一个拷贝，原因是throw语句一旦执行，函数
	// passAndThrow()的执行也将结束localStuff对象被析构从而结束其生命周期
	// 如果把localStuff本身(而不是他的拷贝)传递给catch子句，这个子句接受到
	// 的只是一个被析构了的对象，一个localStuff的尸体，这是无法使用的
	// 因此C++规范要求被作为异常抛出的对象必须被复制
	catch(stuff &w){
		w.Addr();
	}

	system("pause");
	return 0;
}