
#ifndef __CLASSC_H__
#define __CLASSC_H__

class classC
{
public:
	classC(int n = 0, double d = 0.0, const char *p = NULL);
	classC(const classC& src);
	classC& operator=(const classC &src);
	~classC();

	void show() const;
	const char* GetP() const;
private:
	int m_n;
	double m_d;
	char *m_p;
};

#endif  //__CLASSC_H__
