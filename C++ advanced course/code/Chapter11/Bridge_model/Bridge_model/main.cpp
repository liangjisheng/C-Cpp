
#include "Abstraction.h"
#include "AbstractionImp.h"
#include <iostream>

using namespace std;

int main()
{
	AbstractionImp *imp = new ConcreteAbstractionImpA();
	Abstraction *Abs = new RefinedAbstraction(imp);
	Abs->Operator();

	system("pause");
	return 0;
}