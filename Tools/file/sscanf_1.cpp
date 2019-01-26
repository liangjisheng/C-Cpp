
#include <stdio.h>

int main() 
{
	// sscanf:从缓冲区中读格式化字符串函数
   char  str[] = "1 2 3...";
   char  s[81];
   char  c;
   int   i;
   float fp;
   // 从缓冲区str中读取数据 
   sscanf( str, "%s", s );
   sscanf( str, "%c", &c );
   sscanf( str, "%d", &i );
   sscanf( str, "%f", &fp );
   // 输出已读取的数据 
   printf( "String    = %s\n", s );
   printf( "Character = %c\n", c );
   printf( "Integer:  = %d\n", i );
   printf( "Real:     = %f\n", fp );

   return 0;
}