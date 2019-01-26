// exe_mean.h -- exception classes for hmean(),hmean()
#include"iostream"

class bad_hmean {
	double v1,v2;
public:
	bad_hmean(double x=0,double y=0) : v1(x),v2(y) {}
	void mesg() const;
};

inline void bad_hmean::mesg() const 
{ std::cout<<"hmean("<<v1<<","<<v2<<"):"
			" invalid arguments: x = -y\n";
}

class bad_gmean {
	double v1,v2;
public:
	bad_gmean(double x=0,double y=0) : v1(x),v2(y) {}
	void mesg() const;
};

inline void bad_gmean::mesg() const
{ 
	std::cout<<"gmean() tow of argumnets must >0.\n";
}