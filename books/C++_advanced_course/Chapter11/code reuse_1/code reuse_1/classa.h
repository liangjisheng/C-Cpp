
#ifndef _CLASS_A_H_
#define _CLASS_A_H_

// ��classa.hͷ�ļ��а���classb.h����һ���õ���ƣ���Ϊ���뵥��ʹ��MyClassA
// ʱ���������classb.h����MyClassA�ж���MyClassA��Ķ�����һ���õ����
// �ö����ָ������һЩ�������˰���MyClassA���ͷ�ļ�,�����˶�classb.h
// ������,ʹ�ô������ñ�ü�
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