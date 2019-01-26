// Abstract Base Class.h -- bank account classes
#ifndef ABSTRACT_BASE_CLASS_H_
#define ABSTRACT_BASE_CLASS_H_

// Abstract Base Class
class AcctABC {
private:
	enum { MAX = 35 };
	char fullname[MAX];
	long acctNum;
	double balance;
protected:
	const char * FullName() const { return fullname; }
	long AcctNum() const { return acctNum; }
	std::ios_base::fmtflags SetFormat() const;
public:
	AcctABC(const char * fn="Nullbody",long an=-1,
		double bal=0.0);
	void Deposit(double);
	virtual void Withdraw(double) = 0;	// pure virtual function
	double Balance() const { return balance; }
	virtual void ViewAcct() const = 0;
	virtual ~AcctABC() {}
};

// Brass Account Class
class Brass : public AcctABC {
public:
	Brass(const char * fn="Nullbody",long an=-1,
		double bal=0.0) : AcctABC(fn,an,bal) {}
	virtual void Withdraw(double);
	virtual void ViewAcct() const;
	virtual ~Brass() {}
};

// BrassPlus Account Class
class BrassPlus : public AcctABC {
private:
	double maxLoan;
	double rate;
	double owesBank;
public:
	BrassPlus(const char * fn="Nullbody",long an=-1,
		double bal=0.0,double ml=500,double r=0.10);
	BrassPlus(const Brass & ba,double ml=500,double r=0.10);
	virtual void WithDraw(double);
	virtual void ViewAcct() const;
	void ResetMax(double m) { maxLoan = m; }
	void ResetRate(double r) { rete = r; }
	void ResetOwes() { owesBank = 0;}
};

#endif