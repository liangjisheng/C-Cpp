
// 格式化读写函数： fscanf 和fprinf 
// fprintf(fp, "%d %6.2f", i, t);
// fscanf(fp, "%d %f", &i, &t);
// 从磁盘文件中按格式读入或输出字符。

#include <stdio.h>

FILE *stream;

void main( void )
{	
	long l;	
	float fp;	
	char s[81];	
	char c;
	
	 // w+ 读写打开或建立一个文本文件，允许读写
	stream = fopen( "fscanf.out", "w+" );	
	if( stream == NULL )		
		printf( "The file fscanf.out was not opened\n" );	
	else		
	{	
		//为什么%f%c之间没有空格 fscanf( stream, "%c", &c );  才能把'x'读取出来？
		fprintf( stream, "%s %ld %f%c", "a-string",65000, 3.14159, 'x' );		
		// Set pointer to beginning of file: 
		// 改变文件的位置指针  fseek(文件类型指针， 位移量， 起始点); 
		// 文件开头          SEEK_SET  0
		// 文件当前位置      SEEK_CUR  1
		// 文件末尾           SEEK_END 2
		fseek( stream, 0L, SEEK_SET );
		// Read data back from file:
		//按照什么顺序输入就按照什么顺序输出
		fscanf( stream, "%s", s );		
		fscanf( stream, "%ld", &l );		
		fscanf( stream, "%f", &fp );		
		fscanf( stream, "%c", &c ); 		
		// Output data read:		
		printf( "%s\n", s );		
		printf( "%ld\n", l );		
		printf( "%f\n", fp );		
		printf( "%c\n", c );	
		
		fclose( stream );		
	}	
}