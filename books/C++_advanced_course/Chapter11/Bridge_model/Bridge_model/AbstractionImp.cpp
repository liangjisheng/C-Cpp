
#include "AbstractionImp.h"
#include <iostream>

using namespace std;

AbstractionImp::AbstractionImp() {}

AbstractionImp::~AbstractionImp() {}

ConcreteAbstractionImpA::ConcreteAbstractionImpA() {}

ConcreteAbstractionImpA::~ConcreteAbstractionImpA() {}

void ConcreteAbstractionImpA::Operator()
{ cout << "ConcreteAbstractionImpA..." << endl; }

ConcreteAbstractionImpB::ConcreteAbstractionImpB() {}

ConcreteAbstractionImpB::~ConcreteAbstractionImpB() {}

void ConcreteAbstractionImpB::Operator()
{ cout << "ConcreteAbstractionImpB..." << endl; }