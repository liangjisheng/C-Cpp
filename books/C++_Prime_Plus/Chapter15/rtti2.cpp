// rtti2.cpp -- using dynamic_cast,typeid,and type_info
#include"iostream"
#include"cstdlib"
#include"ctime"
#include"typeinfo"
using namespace std;

class Grand {
private:
	int hold;
public:
	Grand(int h=0) : hold(h) {}
	virtual void Speak() const { cout<<"I am grand class!\n"; }
	virtual int value() const { return hold; }
	virtual ~Grand() {}
};

class Superb : public Grand {
public:
	Superb(int h=0) : Grand(h) {}
	void Speak() const { cout<<"I am superb class!\n"; }
	virtual void Say() const 
	{ cout<<"I hold the superb value of "<<value()<<"!\n"; }
};

class Magnificent : public Superb {
private:
	char ch;
public:
	Magnificent(int h=0,char c='A') : Superb(h),ch(c) {}
	void Speak() const { cout<<"I am a magnificent class!!\n"; }
	void Say() const { cout<<"I hold the character "<<ch<<
						" and the integer "<<value()<<"!\n"; }
};

Grand * GetOne();

int main() 
{
	srand(time(0));
	Grand *pg;
	Superb * ps;
	for(int i=0;i<5;i++) {
		pg=GetOne();
		cout<<"Now processing type "<<typeid(*pg).name()<<".\n";
		pg->Speak();
		if(ps=dynamic_cast<Superb*>(pg))
			ps->Say();
		if(typeid(Magnificent)==typeid(*pg))
			cout<<"Yes,you're really magnificent.\n";
	}
	return 0;
}

Grand * GetOne() {
	Grand *p;
	switch(rand()%3) {
	case 0:
		p=new Grand(rand()%100); break;
	case 1:
		p=new Superb(rand()%100); break;
	case 2:
		p=new Magnificent(rand()%100,'A'+rand()%26); break;
	}
	return p;
}