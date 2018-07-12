

#include <stdio.h>

// c[0] = "ENTER"
// c[1] = "NEW"
// c[2] = "POINT"
// c[3] = "FIRST"
// []和*是本质一样的运算，即c[i] = *(c + i);

// c和c+i都是char*[]类型，它可以退化成char**类型，
// cp正好是一个char**的数组
// cp[0] = c + 3;
// cp[1] = c + 2;
// cp[2] = c + 1;
// cp[3] = c;
// 引用后就有cp[0][0] = *(c + 3) = c[3] = "FIRST"

// cp是char**[]类型，它可以退化成char***类类型

char *c[] = {"ENTER","NEW","POINT","FIRST"};  
char **cp[] = { c + 3 , c + 2 , c + 1 , c};  
char ***cpp = cp;

int main(void)  
{  
	// ++cpp的值是cp + 1,引用一次后是cp[1] = *(cp + 1) = c + 2,
	// 再引用一次是*cp[1] = *(c + 2) = c[2]
	printf("%s\n", **++cpp);

	// 再++cpp的值是cp + 2,引用一次后是cp[2] = *(cp + 2) = c + 1,
	// 再对这进行--，减后是c,在引用时c[0] = *(c + 0) = "ENTER"
	// 在加3，字符串指针指到ER输出是ER
	printf("%s\n", *--*++cpp+3);  

	// 这时cpp的值是cp + 2,cpp[-2] = *(cpp - 2) = *(cp + 2 - 2) = 
	// *(cp + 0) = cp[0] = c + 3,在引用是*(c + 3) = c[3] = "FIRST"
	// 在加3，字符串指针指到ST输出是ST
	printf("%s\n", *cpp[-2]+3);

	// 这时cpp的值是cp + 2，cpp[-1] = *(cpp - 1) = *(cp + 2 - 1) =
	// *(cp + 1) = cp[1] = c + 2,在[-1]得*(c + 2 -1) = c[1] = "NEW"
	// 在加1，字符串指针指到EW输出是EW
	printf("%s\n", cpp[-1][-1]+1);

	getchar();
	return 0;  
}