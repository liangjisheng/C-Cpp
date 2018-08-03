
/***********************************************************
 * @name: right value refer.cpp
 * @brief: 右值引用
 * @author: 梁基圣
 * @date: 2018/7/31 15:57:58
 * @version: 1.0
 **********************************************************/

#include <iostream>

using namespace std;

class arr
{
public:
	arr() : data(nullptr), n(0) {}
	arr(const arr& a) 
	{
		n = a.n;
		data = new int[n]; 
		for (int i = 0; i < n; ++i)
			data[i] = a.data[i];
	}
	arr(arr&& a) : data(a.data), n(a.n)
	{
		a.data = nullptr;
		a.n = 0;
	}
	arr(int *_a, int _n)
	{
		data = _a;
		n = _n;
		_a = nullptr;
	}
	~arr()
	{
		delete[] data;
		data = nullptr;
		n = 0;
	}
	arr& operator=(const arr& a)
	{
		if (this == &a)
			return *this;

		delete[] data;
		data = nullptr;

		n = a.n;
		data = new int[n];
		for (int i = 0; i < n; ++i)
			data[i] = a.data[i];

		return *this;
	}

	arr& operator=(arr&& a)
	{
		if (data)
			delete[] data;

		data = a.data;
		n = a.n;
		a.data = nullptr;
		a.n = 0;

		return *this;
	}

	const int* begin() const { return data; }
	int* begin() { return data; }
	const int* end() const { return data + n; }
	int* end() { return data + n; }

private:
	int *data;
	int n;
};


int main()
{
	int n = 5;
	int *a = new int[n];
	memset(a, 0, sizeof(int) * n);
	for (int i = 0; i < n; ++i)
		a[i] = i + 1;

	arr myarr(a, n);
	for each(int i in myarr)
		cout << "myarr[i] = " << i << endl;

	return 0;
}
