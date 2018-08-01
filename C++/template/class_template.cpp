#include"iostream"
#include"tchar.h"
#include"string"
using namespace std;

template<typename T>
class compare {
private:
	T m_a;
	T m_b;
public:
	compare(T a,T b) : m_a(a),m_b(b) {}
	T min() { return m_a > m_b ? m_b : m_a; }
	T max() { return m_a > m_b ? m_a : m_b; }
};

int _tmain(int argc,_TCHAR* argv[])
{
	compare<int> intcompare(2,3);
	cout<<"max(2,3)="<<intcompare.max()<<endl;
	cout<<"min(2,3)="<<intcompare.min()<<endl;

	compare<string> stringcompare("a","b");
	cout<<"max(\"a\",\"b\")="<<stringcompare.max()<<endl;
	cout<<"min(\"a\",\"b\")="<<stringcompare.min()<<endl;

	system("pause");
	return 0;
}
