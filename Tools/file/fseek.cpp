
// long ftell( FILE *stream );
// 得到流式文件中的当前位置，用相对于文件开头的位移量来表示。

#include <stdio.h>
#include <stdlib.h>

struct student
{	
	char name[10];	
	int num;	
	int age;	
	char addr[15];	
}boy;

void main()
{	
	FILE *fp;	
	//用于定位第 i 个结构
	int i=1;
	
	if( !(fp = fopen("student-list", "r")) )		
	{	
		printf("Cannot open the file!\n");		
		return;	
	}
	
	//设置文件内部指针指向文件头,此函数没有返回值
	rewind(fp);
	fseek(fp, i*sizeof(struct student), 0); // fseek(文件类型指针， 位移量， 起始点);
	//数据块读写函数：freed :   fread(buffer, size, count, fp);
	fread(&boy, sizeof(struct student), 1, fp);	
	//读取一个学生的容量
	
	/*
	
	  参数说明：
	  
		buffer: 是一个指针
		
		  对fread来说，它是读入数据的存放地址
		  
			对fwrite来说，是要输出数据的地址（均指起始地址）
			
			  size: 要读写的字节数
			  
				count:要进行读写多少个size字节的数据项
				
				  fp:文件指针
				  
	*/
	printf("name number    age    addr\n");	
	printf("%s %5d   %7d      %s\n", boy.name, boy.age, boy.addr);

	getchar();
}