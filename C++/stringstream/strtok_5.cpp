
// 自己实现strtok()函数原理

#include <stdio.h>
#include <string.h>

// 根据函数原型实现strtok()函数
char* myStrtok_origin(char* str_arr, const char* delimiters, char** temp_str)
{
	// 定义一个指针来指向待分解串
	char *b_temp;

	// 判读str_arr是否为空，如果是NULL就以传进来的temp_str作为起始位置
	// 如果不是NULL，则以str_arr为起始位置开始切分
	if (NULL == str_arr)
		str_arr = *temp_str;

	// 跳过待分解字符，扫描delimiters字符开始的所有分解符
	str_arr += strspn(str_arr, delimiters);

	// 判断当前待分解的位置是否为'\0',若是则返回NULL,否则继续
	if (*str_arr == '\0')
		return NULL;

	// 保存当前的待分解串的指针b_temp,调用strpbrk()在b_temp中找分割符
	// 如果找不到，则将temp_str赋值为待分解字符串末尾部'\0'的位置
	// b_temp没有发生变化;若找到则将分解符所在位置赋值为'\0'
	// b_temp相当于被截断了，temp_str指向分隔符的下一位置
	b_temp = str_arr;
	str_arr = strpbrk(str_arr, delimiters);
	if (NULL == str_arr)
		*temp_str = strchr(b_temp, '\0');
	else
	{
		*str_arr = '\0';
		*temp_str = str_arr + 1;
	}

	// 函数最后部分无论找到没找到分隔符，都将b_temp返回
	return b_temp;
}

char* myStrtok(char* str_arr, const char* delimiters)
{
	static char* last;
	return myStrtok_origin(str_arr, delimiters, &last);
}

int main()
{
	char buf[] = "hello@boy@this@is@heima";

	// 使用myStrtok_origin
	char *temp_str = NULL;
	char *str = myStrtok_origin(buf, "@", &temp_str);
	while (str)
	{
		printf("%s\n", str);
		str = myStrtok_origin(NULL, "@", &temp_str);
	}
	printf("\n");

	// 使用myStrtok
	// 现在buf = "hello"，因为上面的myStrtok_origin将@改为'\0'
	char *str1 = myStrtok(buf, "@");
	while (str1)
	{
		printf("%s\n", str1);
		str1 = myStrtok(NULL, "@");
	}

	getchar();
	return 0;
}