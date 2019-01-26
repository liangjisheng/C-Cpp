
// 此程序判断一个exe是32还是64位的

#include <stdio.h>
#include <Windows.h>

int CrnGetImageFileMachine(char *lpFileName);

int main()
{
	printf("此程序用来判断一个exe是32还是64位的\n");
	printf("请输入文件名:\n");
	char szPath[MAX_PATH] = {0};
	scanf("%s", &szPath);
	// GetModuleFileNameA(NULL, szPath, MAX_PATH);

	int n = CrnGetImageFileMachine(szPath);
	printf("此exe的位数是:");
	if(n == 0x014C)
		printf("x86\n");		// 32bit
	else if(n == 0x0200)
		printf("IA64\n");		// 纯64bit
	else if(n == 0x8664)
		printf("x64\n");		// 64bit
	else
		printf("Unknow\n");

	getchar();
	return 0;
}

int CrnGetImageFileMachine(char *lpFileName)
{
	IMAGE_DOS_HEADER idh;
	FILE *f = fopen(lpFileName, "rb");
	fread(&idh, sizeof(idh), 1, f);
	IMAGE_FILE_HEADER ifh;
	fseek(f, idh.e_lfanew + 4, SEEK_SET);		// 从文件头偏移
	fread(&ifh, sizeof(ifh), 1, f);
	fclose(f);

	return ifh.Machine;
}