
int exe_32or64(LPCTSTR ExePath)
{
	IMAGE_DOS_HEADER idh;  
	CFile file(ExePath, CFile::typeBinary | CFile::modeRead);
	file.Read(&idh, sizeof(idh));
	IMAGE_FILE_HEADER ifh;
	file.Seek(idh.e_lfanew + 4, CFile::begin);
	file.Read(&ifh, sizeof(ifh));
	file.Close();

	/*	IMAGE_DOS_HEADER idh; 
		FILE *f = fopen(lpFileName, "rb");  
		fread(&idh, sizeof(idh), 1, f);  
		IMAGE_FILE_HEADER ifh;
		fseek(f, idh.e_lfanew + 4, SEEK_SET);  
		fread(&ifh, sizeof(ifh), 1, f);  
		fclose(f);*/  

	if(ifh.Machine == 0x014C)
		return 32;
		// printf("x86\n");		// 32bit
	else if(ifh.Machine == 0x0200)
		return 64;
		// printf("IA64\n");		// 纯64bit
	else if(ifh.Machine == 0x8664)
		return 64;
		// printf("x64\n");		// 64bit
	else
		return 0;
		// printf("Unknow\n");
}