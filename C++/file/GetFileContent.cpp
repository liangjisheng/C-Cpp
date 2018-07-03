/************************************************************************/
/* 
	函数功能:获取一个文件的二进制流
	buffer:存储文件的二进制流
	filePath:文件路径
	返回文件的大小
*/
/************************************************************************/
int GetFileContent(char **buffer, const char *filePath)
{
	int fileLength = 0;
	FILE *fp = fopen(filePath,"rb");
	if (NULL == fp)
		return 0;

	fseek(fp,0,SEEK_END);
	fileLength = ftell(fp);
	rewind(fp);

	*buffer = new char[fileLength+1];
	memset(*buffer,0,fileLength+1);
	fseek(fp,0,SEEK_SET);
	fread(*buffer,sizeof(char),fileLength,fp);
	fclose(fp);
	return fileLength;
}