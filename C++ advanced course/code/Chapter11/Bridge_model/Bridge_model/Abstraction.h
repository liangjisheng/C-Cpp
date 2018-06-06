
// Bridge 模式

#ifndef _ABSTRACTION_H_
#define _ABSTRACTION_H_

class AbstractionImp;

class Abstraction
{
public:
	virtual ~Abstraction();
	virtual void Operator() = 0;
protected:
	Abstraction();
private:
};

class RefinedAbstraction : public Abstraction
{
public:
	RefinedAbstraction(AbstractionImp *imp);
	virtual ~RefinedAbstraction();
	virtual void Operator();
protected:
private:
	AbstractionImp *_imp;
};

#endif // _ABSTRACTION_H_