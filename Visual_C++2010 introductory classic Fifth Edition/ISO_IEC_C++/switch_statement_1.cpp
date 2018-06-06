// switch_statement_1.cpp
#include <stdio.h>
#include <string.h>

int main() {
	char* buffer="Any character stream";
	int capa,lettera,nota;
	char c;
	capa = lettera = nota = 0;

	printf_s("\nLength of buffer: %d\n",strlen(buffer));

	while ( c = *buffer++)
	{
		switch ( c )
		{
		case 'A':
			capa++;
			break;
		case 'a':
			lettera++;
			break;
		default:
			nota++;
		}
	}
	printf_s("\nUppercase a: %d\nLowercase a: %d\nTotal: %d\n",
		capa,lettera,(capa+lettera+nota) );

	getchar();
	return 0;
}