
#ifndef __CLASSB_H__
#define __CLASSB_H__

class classB
{
public:
	classB(int n = 0, double d = 0.0, const char *p = NULL);
	classB(const classB& src);
	classB(classB && src);
	classB& operator=(const classB &src);
	~classB();

	void show() const;
	const char* GetP() const;
	const int* GetAddressN() const;
private:
	int m_n;
	double m_d;
	char *m_p;
};

#endif  //__CLASSB_H__
