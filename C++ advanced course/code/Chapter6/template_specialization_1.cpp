
// ģ���ػ���ͬ��ģ��ʵ��������ָ���˺���ģ�������������(ģ�����Ϊĳ���ض�
// ����)�µ�ʵ�ְ汾��


#include <iostream>
#include <string.h>

using std::cout;
using std::endl;

template<typename T>
T myMax(T t1, T t2) { return t1 > t2 ? t1 : t2; }

typedef const char* PCC;

// const char*��ʾ�ػ�������������ͨ��ģ��Ķ����ʵ��
//template<> 
//PCC myMax<PCC>(PCC s1, PCC s2) { return (strcmp(s1, s2) > 0) ? s1 : s2; }


// ��������Ϊconst char*�����غ���,���溯��ģ����ػ�
PCC myMax(PCC s1, PCC s2) { return (strcmp(s1, s2) > 0) ? s1 : s2; }


// ��ͨ���غ�����ʹ��ģ���ػ�֮��Ĳ�ͬ��
// ʹ����ͨ���غ����������Ƿ���ʵ�ʵĺ������ã�������Ŀ���ļ������ɸú�����
// �����ƴ��롣�����ʹ��ģ����ػ��汾�����Ƿ����������ã����򲻻���Ŀ���ļ�
// �а����ػ�ģ�庯���Ķ����ƴ��룬���Ϻ���ģ��Ķ���ʵ����׼��
// ʹ����ͨ���غ������ڷ������ģʽ�£�Ӧ���ڸ���Դ�ļ��а������غ���������
// ������ĳЩԴ�ļ��оͻ�ʹ��ģ��ʵ���������������غ���


int main()
{
	// myMax<int>(int, int);
	int i = myMax(10, 5);

	// ������ʾ�ػ�:const char* myMax<const char*>(const char*, const char*)
	const char *p = myMax("very", "good");

	cout << i << endl;
	cout << p << endl;		// very
	cout << *p << endl;		// v

	system("pause");
	return 0;
}

