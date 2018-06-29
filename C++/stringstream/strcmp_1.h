int strcmp(char* source,char* dest)
{
	assert((source!=NULL) && (dest!=NULL));
	int i,j;
	for(i=0;source[i]==dest[j];i++) {
		if(source[i]=='\0' && dest=='\0') return 0;
		else return -1;
	}
}