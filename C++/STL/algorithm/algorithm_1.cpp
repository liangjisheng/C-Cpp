#include"iostream"
#include"vector"
#include"string"
#include"algorithm"
using namespace std;

class Student;
ostream& operator <<(ostream& os,const Student& s);

class Student {
private:
	string m_strName;
	int m_nHeight;
public:
	Student(string strName="",int Height=0)
		: m_strName(strName),m_nHeight(Height) {}
	Student(const Student& s);
	Student& operator= (const Student& s);
	int GetHeight() const { return m_nHeight; }
	string GetName() const { return m_strName;}
	friend ostream& operator <<(ostream& os,const Student& s);
	bool operator==(const Student& s);
};

Student::Student(const Student& s) {
	m_strName=s.GetName();
	m_nHeight=s.GetHeight();
}

Student& Student::operator =(const Student& s) {
	m_strName=s.GetName();
	m_nHeight=s.GetHeight();
	return *this;
}

ostream& operator <<(ostream& os,const Student& s) {
	os<<"Name:"<<s.GetName()<<",Height:"<<s.GetHeight();
	return os;
}

bool Student::operator ==(const Student& s) {
	return m_strName==s.GetName() && m_nHeight==s.GetHeight();
}

void print(const Student& s) { cout<<s<<endl; }

bool sortbyHeight(const Student& s1,const Student s2)
{ return s1.GetHeight() < s2.GetHeight(); }

int main()
{
	Student s1("li",123),s2("shu",234),s3("yu",345);
	vector<Student> vecStu;
	vecStu.push_back(s1);
	vecStu.push_back(s2);
	vecStu.push_back(s3);

	cout<<"vecStu:"<<endl;
	for_each(vecStu.begin(),vecStu.end(),print);
	cout<<endl;
	
	vector<Student> vecStu1;
	vecStu1.push_back(Student("shu",321));
	vecStu1.push_back(Student("ji",654));
	vecStu1.push_back(Student("yu",345));

	cout<<"vecStu1:"<<endl;
	for_each(vecStu1.begin(),vecStu1.end(),print);
	cout<<endl;

	vecStu.resize(vecStu.size()+vecStu1.size());
	copy_backward(vecStu1.begin(),vecStu1.end(),vecStu.end());

	cout<<"vecStu:"<<endl;
	for_each(vecStu.begin(),vecStu.end(),print);
	cout<<endl;

	sort(vecStu.begin(),vecStu.end(),sortbyHeight);

	cout<<"After sort vecStu:"<<endl;
	for_each(vecStu.begin(),vecStu.end(),print);
	cout<<vecStu.size()<<endl;
	cout<<endl;

	// unique()删除容器中冗余的元素，返回最后数据的位置
	vector<Student>::iterator itend=unique(vecStu.begin(),vecStu.end());

	cout<<"After unique vecStu:"<<endl;
	for_each(vecStu.begin(),vecStu.end(),print);
	cout<<vecStu.size()<<endl;
	cout<<endl;

	// 将因删除而遗留下来的多余元素清理
	vecStu.erase(itend,vecStu.end());

	cout<<"After erase vecStu:"<<endl;
	for_each(vecStu.begin(),vecStu.end(),print);
	cout<<vecStu.size()<<endl;
	cout<<endl;

	system("pause");
	return 0;
}