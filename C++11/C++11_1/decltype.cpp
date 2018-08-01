#include <iostream>
#include <string>

using namespace std;

// Forward class declaration
class myString;

class myInt
{
public:
	myInt(int num = 0) : mValue(num) {}
	myInt operator+(const myString& rhs) const;
	int getInt() const { return mValue; }

private:
	int mValue;
};


class myString
{
public:
	myString(const std::string& str = "test") : mString(str) {}
	myString operator+(const myInt& rhs) const;
	const std::string& getString() const { return mString; }

private:
	std::string mString;
};


myInt myInt::operator+(const myString& rhs) const
{
	return mValue + stoi(rhs.getString());
}


myString myString::operator+(const myInt& rhs) const 
{
	string str = mString;
	str.append(to_string(rhs.getInt()));
	return str;
}



// 可以编写一个函数模板执行加法运算，需要显示指定函数模板返回类型
//template<typename T1, typename T2, typename Result>
//Result DoAddition(const T1& t1, const T2& t2)
//{
//	return t1 + t2;
//}


// 不需要显示指定返回类型,编译器自动推到函数模板返回类型
template<typename T1, typename T2>
auto DoAddition(const T1& t1, const T2& t2) -> decltype(t1 + t2)
{
	return t1 + t2;
}


int main()
{
	myInt i(4);
	myString str("5");
	myInt a = i + str;
	myString b = str + i;

	auto e = DoAddition(i, str);
	cout << "Integer: " << e.getInt() << endl;
	auto f = DoAddition(str, i);
	cout << "String: " << f.getString() << endl;

	//auto c = DoAddition<myInt, myString, myInt>(i, str);
	//cout << c.getInt() << endl;

	//auto d = DoAddition<myString, myInt, myString>(str, i);
	//cout << d.getString() << endl;

	//cout << "Integer: " << a.getInt() << endl;
	//cout << "String: " << b.getString() << endl;

	return 0;
}
