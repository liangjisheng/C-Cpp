char* strcat(char* strDest,const char* strSrc)
{
	assert(strDest!=NULL && strSrc!=NULL);
	char* p=strDest;
	while(p!='\0') p++;
	char* p1=strSrc;
	while(p1!='\0')
		*p++=*p1++;
	*p='\0';
	return strDest;
}