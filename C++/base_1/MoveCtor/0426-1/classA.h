
#ifndef __CLASSA_H__
#define __CLASSA_H__

class classA
{
public:
	classA(int n = 0, double d = 0.0);
	classA(const classA& src);
	~classA();

	void show() const;
private:
	int m_n;
	double m_d;
};

#endif  //__CLASSA_H__
