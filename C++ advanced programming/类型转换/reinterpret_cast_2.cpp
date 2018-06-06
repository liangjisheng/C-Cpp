// MSDN��VC++ Developer Center ������reinterpret_cast��ʹ�ü�ֵ
// ����������ϣ����
#include <iostream>
#include <iomanip>

using namespace std;

// Returns a hash code based on an address
unsigned short myHash(void* p)
{
	// ָ��ת��Ϊ������
	unsigned int val = reinterpret_cast<unsigned int>(p);
	return (unsigned short)(val ^ (val >> 16));
}

int main()
{
	int a[20];
	for(int i = 0; i < 20; i++)
		cout << dec << myHash(a + i) << "\t0x" << hex << myHash(a + i) << endl;

	system("pause");
	return 0;
}