
#include "abstraction.h"
#include "AbstractionImp.h"
#include <iostream>

using namespace std;

Abstraction::Abstraction() {}

Abstraction::~Abstraction() {}

RefinedAbstraction::RefinedAbstraction(AbstractionImp *imp)
{ _imp = imp; }

RefinedAbstraction::~RefinedAbstraction() {}

void RefinedAbstraction::Operator() { _imp->Operator(); }