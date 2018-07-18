int strcmp(char *source,char* dest)
{
	assert((source!=NULL) && (dest!=NULL));
	while(*source++==*dest++ && source && dest);
	if(source=='\0' && dest=='\0') return 0;
	else return -1;
}