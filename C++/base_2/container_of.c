
#include <stdio.h>
#include <string.h>

// 获取结构体TYPE的变量成员MEMBER在此结构体中的偏移量
#define offsetof(TYPE, MEMBER) ((size_t)(&((TYPE *)0)->MEMBER))

/*******************************************************************************
 * 根据结构体type变量中的域成员变量member的指针ptr来获取指向整个结构体变量的指针
 * (01)typeof(((type *)0)->member)取出member成员的变量类型
 * (02)const typeof(((type *)0)->member) *__mptr = (ptr);定义变量__mptr指针,并将ptr
 * 赋值给__mptr,经过这一步__mptr为member数据类型的常量指针,其指向ptr所指向的地址
 * (03)(char *)__mptr将__mptr转换为字节型指针
 * (04)offsetof(type, member)获取member成员在结构体type中的位置偏移
 * (05)(char *)__mptr - offsetof(type, member)计算结构体type指针的起始地址(char*)
 * (06)(type *)( (char *)__mptr - offsetof(type, member) );将char*类型的结构体type
 *     的指针转换为type*类型的结构体type的指针
********************************************************************************/
#define container_of(ptr, type, member) ({\
	const typeof(((type *)0)->member) *__mptr = (ptr);\
	(type *)( (char *)__mptr - offsetof(type, member) );})


struct student
{
	char gender;
	int id;
	int age;
	char name[20];
};


void main()
{
	struct student stu;
	struct student *pstu;

	stu.gender = '1';
	stu.id = 9527;
	stu.age = 24;
	strcpy(stu.name, "liangjisheng");

	// 根据id地址获取结构体地址
	pstu = container_of(&stu.id, struct student, id);

	// 根据指针访问其他成员
	printf("gender = %c\n", pstu->gender);
	printf("age = %d\n", pstu->age);
	printf("name = %s\n", pstu->name);

	getchar();
}