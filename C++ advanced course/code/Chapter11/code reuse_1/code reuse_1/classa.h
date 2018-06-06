
#ifndef _CLASS_A_H_
#define _CLASS_A_H_

// 在classa.h头文件中包含classb.h不是一个好的设计，因为当想单独使用MyClassA
// 时，必须包含classb.h，在MyClassA中定义MyClassA类的对象不是一个好的设计
// 用对象的指针会更好一些，避免了包含MyClassA类的头文件,摆脱了对classb.h
// 的依赖,使得代码重用变得简单
// #include "classb.h"

class MyClassB;

class MyClassA
{
private:
	// MyClassB mobj;
	MyClassB *m_pobj;
public:
	void ShowObject();
	MyClassA();
	~MyClassA();
};

#endif //_CLASS_A_H_