#pragma once
// Name.h - Definition of the Name class

class Name
{
public:
	Name();
	Name(const char* pFirst, const char* pSecond);
	Name(const Name& name);
	Name& operator=(const Name& name);
	~Name();
	char* getName(char* pName) const; // pName容纳姓名的char数组指针
	size_t getNmaeLength() const;

	// Comparison operators for names
	bool operator<(const Name& name) const;
	bool operator==(const Name& name) const;
	bool operator>(const Name& name) const;

private:
	char* pFirstname;
	char* pSecondname;
};