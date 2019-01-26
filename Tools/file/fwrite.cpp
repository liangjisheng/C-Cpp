

// 二进制文件的读写，
// fwrite(buffer, size, count, fp);
#include <stdio.h>

#define SIZE 4

struct student
{	
	char name[10];	
	int num;	
	int age;	
	char addr[15];	
}stu[SIZE];

void save()
{	
	FILE *fp;	
	int i;	
	// “wb” 只写打开或建立一个二进制文件，只允许写数据		
	if( !(fp = fopen("student-list", "wb")) ) 
	{		
		printf("Cannot open the file!\n");		
		return;		
	}	
	
	for( i=0; i<SIZE; i++ )		
	{		
		if( fwrite(&stu[i], sizeof(struct student), 1, fp) !=1 )			
		{			
			printf("File write error!\n");			
			fclose(fp);			
		}		
	}	
}

void main()
{	
	int i;	
	printf("Please input the student's name, num, age and address: \n");	

	for ( i=0; i<SIZE; i++ )		
		scanf("%s %d %d %s", &stu[i].name, &stu[i].num, &stu[i].age, &stu[i].addr );
	
	save();
	
	getchar();
}