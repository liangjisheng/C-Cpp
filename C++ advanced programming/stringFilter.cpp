
// Hash����ʹ�� O(1)ʱ��������ݵĲ��롢ɾ���Ͳ��ң�
// ���� hash ����֤�������ݵ������ԣ������� hash 
// ���в���������ݻ�����С���ݵ�ʱ���� O(N) ��

// �ַ�������ɹ����ظ��ַ��Ĺ��ܣ�
// ����:1.���ַ�����2.�ַ������ȣ�3.��out������������˺���ַ���.
// ��������˺���ַ�����

// ˼·1, ѭ���ж�����
// ��1�����ȼ�¼�ַ����е�1���ַ�����2����Ȼ��ӵ�2���ַ���ʼ��
// �ж������ǰ����ַ��Ƿ���ͬ������ͬ�Ļ�����ͳ�ƽ�ȥ��
// ��ͬ�Ļ������������ֱ���ַ���ĩβ��������\0������ʱ�临�Ӷȣ�O��n2����

// ˼·2, ��ϣ����˷���
// ��1������ʼ��һ����ϣ�����Դ洢�ַ���key�����ַ����ֵĴ�����
// ��2����������ϣ������ͳ�Ƽ�����
// ��3�������ͳ�ƴ���Ϊ1��ͳ�ƴ�������1�ģ����1�Σ���ʱ�临�Ӷȣ�O��n����

#include <iostream>
#include <string.h>

using std::cout;
using std::endl;


// ѭ���ж������˵��ظ��ַ���ʱ�临�Ӷ�ΪO(n^2)
void stringFilter(const char* pInputStr, long lInputLen, char* pOutputStr)
{
	if(NULL == pInputStr || 0 == lInputLen || NULL ==pOutputStr)
		return ;

	int nCnt = 0;
	*pOutputStr = pInputStr[0];		// �ȴ����һ��
	++nCnt;

	int nNotEqualCnt = 0;			// ͳ�Ƽ���
	for(int i = 1; i < lInputLen; i++)
	{
		nNotEqualCnt = 0;
		for(int j = i - 1; j >= 0; j--)
		{
			if(pInputStr[i] != pInputStr[j])
				++nNotEqualCnt;
		}
		if(nNotEqualCnt == i)			// ��ǰ��Ķ���һ��
			pOutputStr[nCnt++] = pInputStr[i];
	}

	pOutputStr[nCnt] = '\0';
}


// ��ϣ�������ַ����е��ظ��ַ�,��ʵ���ù�ϣ��ͳ���ַ����ַ����г��ֵĴ���
// hashTable��ֵ��һ��Ϊ1��Ӧ���ַ��������ַ����е�һ�����ظ����ַ�
// ʹ�ù�ϣ��ֻ������ַ���һ�Σ�ʱ�临�Ӷ�ΪO(n)
void stringFilterFast(const char* pInputStr, long lInputLen, char* pOutputStr)
{
	const unsigned int size = 256;
	unsigned int hashTable[size] = {0};
	const char* pHashKey = pInputStr;
	int outPutCnt = 0;

	if(NULL == pInputStr)
		return ;

	// ��pInputStr������ϣ����,���ַ���ASCII��ֵ��Ϊ�±꣬
	// ͳ��һ���ַ����ַ����г��ֵĴ���
	while(*pHashKey != '\0')
	{
		hashTable[*pHashKey]++;
		pHashKey++;
	}

	// �������hashTable�У���ϣֵ��һ��Ϊ1����Ӧ���ַ���
	// ����ĳ���ַ����е�һ�����ظ����ַ�
	pHashKey = pInputStr;
	while(*pHashKey != '\0')
	{
		if(1 == hashTable[*pHashKey])			// �洢ֻ���ֹ�һ�ε�
			pOutputStr[outPutCnt++] = *pHashKey;
		else if(hashTable[*pHashKey] > 1)		// �洢���ֹ���ε�
		{
			pOutputStr[outPutCnt++] = *pHashKey;
			hashTable[*pHashKey] = 0;
		}
		pHashKey++;
	}

	pOutputStr[outPutCnt] = '\0';
}


int main()
{
	char szSrc[] = "asdfghjklasdf";
	char szDest[128] = {0};
	stringFilter(szSrc, strlen(szSrc), szDest);
	if(szDest)
		cout << szDest << endl;

	stringFilterFast(szSrc, strlen(szSrc), szDest);
	if(szDest)
		cout <<szDest << endl;

	system("pause");
	return 0;
}