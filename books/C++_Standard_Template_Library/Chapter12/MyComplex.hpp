
#ifndef __MYCOMPLEX_H__
#define __MYCOMPLEX_H__

#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>

using namespace std;

class MyComplex
{
protected:
	double _real;
	double _image;

public:
	MyComplex(double real = 8.0, double image = 6.0) : _real(real), _image(image)
	{
		cout << "MyComplex(double real, double image)" << endl;
	}

	MyComplex(const MyComplex& d)
	{
		cout << "MyComplex(const MyComplex& d)" << endl;
		_real = d._real;
		_image = d._image;
	}

	~MyComplex()
	{
		cout << "~MyComplex()" << endl;
		_real = 0.0;
		_image = 0.0;
	}

	MyComplex& operator = (const MyComplex& d)
	{
		cout << "=" << endl;
		if (this != &d)
		{
			_real = d._real;
			_image = d._image;
		}
		return *this;
	}

	void Display() const 
	{
		cout << "_real: " << _real;
		cout << "      _image: " << _image << endl;
	}

	bool operator == (const MyComplex& d)
	{
		cout << "==" << endl;
		return this->_real == d._real && this->_image == d._image;
	}

	bool operator != (const MyComplex& d)
	{
		cout << "!=" << endl;
		return this->_real != d._real && this->_image != d._image;
	}

	// 复数只有当虚部为0是，即_image = 0时，才可以比较大小，这时比较的是_real的大小
	bool operator > (const MyComplex& d)
	{
		if (this->_image != 0 || d._image != 0)
		{
			cout << "can not compare" << endl;
			return false;
		}
		else
			return this->_real > d._real;
	}

	bool operator < (const MyComplex& d)
	{  
		if (this->_image != 0 || d._image != 0)  
		{  
			cout << "can not compare" << endl;
			return false;
		}  
		else
			return this->_real < d._real;
	}

	bool operator <= (const MyComplex& d)
	{  
		if (this->_image != 0 || d._image != 0)  
		{  
			cout << "can not compare" << endl;
			return false;
		}  
		else
			return this->_real <= d._real;
	}

	bool operator >= (const MyComplex& d)
	{  
		if (this->_image != 0 || d._image != 0)  
		{  
			cout << "can not compare" << endl;
			return false;
		}  
		else
			return this->_real >= d._real;
	}

	MyComplex operator + (const MyComplex& d)
	{
		cout << "+" << endl;
		MyComplex ret;
		ret._real = this->_real + d._real;
		ret._image = this->_image + d._image;
		return ret;
	}

	MyComplex& operator += (const MyComplex& d)
	{
		cout << "+=" << endl;
		this->_real += d._real;
		this->_image += d._image;
		return *this;
	}

	MyComplex& operator ++ ()
	{
		cout << "forward ++" << endl;
		this->_real += 1;
		return *this;
	}

	MyComplex operator ++ (int)
	{
		cout << "backward ++" << endl;
		MyComplex tmp(*this);
		this->_real += 1;
		return tmp;
	}
};

#endif  //__MYCOMPLEX_H__
