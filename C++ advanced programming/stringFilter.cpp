
// Hash表是使用 O(1)时间进行数据的插入、删除和查找，
// 但是 hash 表不保证表中数据的有序性，这样在 hash 
// 表中查找最大数据或者最小数据的时间是 O(N) 。

// 字符串中完成过滤重复字符的功能，
// 输入:1.常字符串；2.字符串长度；3.【out】用于输出过滤后的字符串.
// 输出：过滤后的字符串。

// 思路1, 循环判定法。
// 第1步，先记录字符串中第1个字符；第2步，然后从第2个字符开始，
// 判定其和其前面的字符是否相同，不相同的话，则统计进去；
// 相同的话则继续遍历，直到字符串末尾（遇到’\0’）。时间复杂度：O（n2）。

// 思路2, 哈希表过滤法。
// 第1步，初始化一个哈希表，用以存储字符（key）及字符出现的次数；
// 第2步，遍历哈希表，进行统计计数；
// 第3步，输出统计次数为1及统计次数多余1的（输出1次）。时间复杂度：O（n）。

#include <iostream>
#include <string.h>

using std::cout;
using std::endl;


// 循环判定发过滤掉重复字符，时间复杂度为O(n^2)
void stringFilter(const char* pInputStr, long lInputLen, char* pOutputStr)
{
	if(NULL == pInputStr || 0 == lInputLen || NULL ==pOutputStr)
		return ;

	int nCnt = 0;
	*pOutputStr = pInputStr[0];		// 先处理第一个
	++nCnt;

	int nNotEqualCnt = 0;			// 统计计数
	for(int i = 1; i < lInputLen; i++)
	{
		nNotEqualCnt = 0;
		for(int j = i - 1; j >= 0; j--)
		{
			if(pInputStr[i] != pInputStr[j])
				++nNotEqualCnt;
		}
		if(nNotEqualCnt == i)			// 和前面的都不一样
			pOutputStr[nCnt++] = pInputStr[i];
	}

	pOutputStr[nCnt] = '\0';
}


// 哈希表法过滤字符串中的重复字符,其实利用哈希表统计字符在字符串中出现的次数
// hashTable中值第一个为1对应的字符，就是字符串中第一个不重复的字符
// 使用哈希表，只需遍历字符串一次，时间复杂度为O(n)
void stringFilterFast(const char* pInputStr, long lInputLen, char* pOutputStr)
{
	const unsigned int size = 256;
	unsigned int hashTable[size] = {0};
	const char* pHashKey = pInputStr;
	int outPutCnt = 0;

	if(NULL == pInputStr)
		return ;

	// 将pInputStr读到哈希表中,以字符的ASCII码值作为下标，
	// 统计一个字符在字符串中出现的次数
	while(*pHashKey != '\0')
	{
		hashTable[*pHashKey]++;
		pHashKey++;
	}

	// 输出，在hashTable中，哈希值第一个为1所对应的字符，
	// 就是某个字符串中第一个不重复的字符
	pHashKey = pInputStr;
	while(*pHashKey != '\0')
	{
		if(1 == hashTable[*pHashKey])			// 存储只出现过一次的
			pOutputStr[outPutCnt++] = *pHashKey;
		else if(hashTable[*pHashKey] > 1)		// 存储出现过多次的
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