
#include <stdio.h>
#include <string.h>

const int MAX_NAME_SIZE = 30;

class Student
{
public:
	Student(char *pszName);
	~Student();

public:
	static void PrintAllStudents();
private:
	char m_name[MAX_NAME_SIZE];
	Student *next;
	Student *prev;
	static Student *m_head;
};

Student* Student::m_head = NULL;


Student::Student(char *pszName)
{
	memset(m_name, 0, MAX_NAME_SIZE);
	strcpy(this->m_name, pszName);

	// 建立双向链表，新数据从链表头部插入
	this->next = m_head;
	this->prev = NULL;
	if (m_head)
		m_head->prev = this;
	m_head = this;
}

Student::~Student()
{
	if (this == m_head)		// 该节点就是头节点
		m_head = this->next;
	else
	{
		this->prev->next = this->next;
		this->next->prev = this->prev;
	}
};

void Student::PrintAllStudents()
{
	for (Student *p = m_head; p; p = p->next)
		printf("%s\n", p->m_name);
}


void main()
{
	Student a("AAA");
	{
		Student b("BBB");
		Student::PrintAllStudents();
	}
	printf("\n");
	Student b("BBB");
	Student c("CCC");
	Student d("DDD");

	Student::PrintAllStudents();

	getchar();
}