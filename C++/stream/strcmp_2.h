int strcmp(char* source,char* dest)
{
	assert((source!=NULL) && (dest!=NULL));
	while((*source!='\0') && (*source==*dest))
	{ source++; dest++; }
	return ((*source) - (*dest)) ? -1 : 0;
}