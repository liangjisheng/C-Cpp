
#ifndef __NULLPOINTCALL_H__
#define __NULLPOINTCALL_H__

class CNullPointCall
{
public:
	static void test1();
	void test2();
	void test3(int nNum);
	void test4();
private:
	static int m_nStatic;
	int m_nNum;
};

#endif  //__NULLPOINTCALL_H__
