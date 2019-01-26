
#include "classa.h"
#include "classb.h"

MyClassA::MyClassA() { m_pobj = new MyClassB; }

MyClassA::~MyClassA() { delete m_pobj; } 

void MyClassA::ShowObject() { m_pobj->show(); }