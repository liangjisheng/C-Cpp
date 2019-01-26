
#include <iostream>
#include <vector>
#include <stdio.h>
#include <tchar.h>
#include <fstream>

using namespace std;

int main()
{
	vector<vector<wchar_t> > vecTempAddress;
	vector<wchar_t> vectmp;
	FILE *pSrcFile = NULL;
	pSrcFile = _tfopen(_T("D:\\file.txt"), _T("rb"));
	if(pSrcFile == NULL)
		return -1;
	
	fseek(pSrcFile, 0, SEEK_END);
	int nLength = ftell(pSrcFile);
	fseek(pSrcFile, 0, SEEK_SET);
	wchar_t *content = new wchar_t[nLength];
	memset(content, 0, sizeof(wchar_t) * nLength);

	size_t nReadCount = 0;
	nReadCount = fread(content, sizeof(wchar_t), nLength, pSrcFile);
	if(nReadCount)
	{
		for(int i = 1; i <= nLength; i++)
		{
			if(content[i] == 0)
				i = nLength;
			if((content[i]==_T('\r') && i<nLength-1 && content[i+1]==_T('\n'))||i==nLength)
			{
				if(i!=nLength)
				{
					vecTempAddress.push_back(vectmp);
					i++;
				}
				vectmp.clear();
			}
			else
			{
				if(content[i]!=_T(' '))
				{	
					vectmp.push_back(content[i]);
					if(i == nReadCount - 1)
						vecTempAddress.push_back(vectmp);
				}
			}
		}
	}
    int nLength1 = vecTempAddress.size();
    vector<wstring> vecTempAddress1;
	
	for(int i = 0; i < nLength1; i++)
	{
		vector<vector<wchar_t>>::iterator iter = vecTempAddress[i].begin();
		while(iter != vecTempAddress[i].end())
		{
			vecTempAddress1.push_back(*iter);
		}
	}
	fclose(pSrcFile);
	delete [] content;
	content = NULL;

	system("pause");
	return 0;
}