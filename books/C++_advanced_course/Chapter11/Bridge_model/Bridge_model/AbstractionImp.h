
#ifndef _ABSTRACTIONIMP_H_
#define _ABSTRACTIONIMP_H_

class AbstractionImp
{
public:
	virtual ~AbstractionImp();
	virtual void Operator() = 0;
protected:
	AbstractionImp();
private:
};

class ConcreteAbstractionImpA : public AbstractionImp
{
public:
	ConcreteAbstractionImpA();
	~ConcreteAbstractionImpA();
	virtual void Operator();
protected:
private:
};

class ConcreteAbstractionImpB : public AbstractionImp
{
public:
	ConcreteAbstractionImpB();
	~ConcreteAbstractionImpB();
	virtual void Operator();
protected:
private:
};

#endif