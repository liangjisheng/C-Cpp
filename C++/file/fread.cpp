

// 二进制文件的读写，
// fread(buffer, size, count, fp);
#include <stdio.h>
#define SIZE 4

struct student
{	
	char name[10];	
	int num;	
	int age;	
	char addr[15];	
}stu[SIZE];

void load();

void main()
{	
	int i;	
	load();	
	printf("      name     num    age      adress\n\n");	
	for ( i=0; i<SIZE; i++ )
		printf("%10s %5d %5d %10s \n", &stu[i].name, &stu[i].num, &stu[i].age, &stu[i].addr );	
}

void load()
{	
	FILE *fp;	
	int i;	
	if( !(fp = fopen("student-list", "r")) )		
	{		
		printf("Cannot open the file!\n");		
		return;		
	}	
	for( i=0; i<SIZE; i++ )
		fread(&stu[i], sizeof(struct student), 1, fp);	
	
	fclose(fp);	
}