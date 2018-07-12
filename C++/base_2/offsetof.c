
#include <stdio.h>

/************************************************************************
 * 获取结构体TYPE的变量成员MEMBER在此结构体中的偏移量
 * ((TYPE *)0)将0转换成TYPE类型的指针,即TYPE类型的指针的地址是0
 * ((TYPE *)0)->MEMBER访问结构体中的成员
 * (&((TYPE *)0)->MEMBER))取出数据成员的地址,由于TYPE的地址是0,这里得到的
 * 地址就是相对MEMBER在TYPE中的偏移
 * ((size_t)(&((TYPE *)0)->MEMBER))结果转换类型,32位系统,size_t是unsigned int
 * 64位系统,size_t是unsigned long
************************************************************************/
#define offsetof(TYPE, MEMBER) ((size_t)(&((TYPE *)0)->MEMBER))

struct student
{
	char gender;
	int id;
	int age;
	char name[20];
};

void main()
{
	int gender_offset, id_offset, age_offset, name_offset;

	gender_offset = offsetof(struct student, gender);
	id_offset = offsetof(struct student, id);
	age_offset = offsetof(struct student, age);
	name_offset = offsetof(struct student, name);

	printf("sizeof(struct student) = %d\n", sizeof(struct student));
	printf("gender_offset = %d\n", gender_offset);
	printf("id_offset = %d\n", id_offset);
	printf("age_offset = %d\n", age_offset);
	printf("name_offset = %d\n", name_offset);

	getchar();
}
  