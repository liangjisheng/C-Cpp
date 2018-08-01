#include"memory"
#include"vector"
#include"tchar.h"
#include"iostream"
#include"string"
using namespace std;

class Employee {
private:
	string m_strName;
public:
	Employee(string strName) { m_strName=strName; }
	string GetName() { return m_strName; }
};

// 英文打印员工信息
class PrintEng {
private:
	shared_ptr<Employee> m_spEmp;
public:
	PrintEng(shared_ptr<Employee> sp) : m_spEmp(sp) {}
	void doPrint() {
		if(true==(bool)m_spEmp)
			cout<<"Name of Employee:"<<m_spEmp->GetName()<<endl;
	}
};

// 中文打印员工信息
class PrintChs {
private:
	shared_ptr<Employee> m_spEmp;
public:
	PrintChs(shared_ptr<Employee> sp) : m_spEmp(sp) {}
	void doPrint() {
		if(true==(bool)m_spEmp)
			cout<<"员工的名字是:"<<m_spEmp->GetName()<<endl;
	}
};

int _tmain(int argc,_TCHAR* argv[])
{
	shared_ptr<Employee> spEmp(new Employee("lishuyu"));
	
	cout<<"sizeof(spEmp)="<<sizeof(spEmp)<<endl;
	cout<<"引用计数:"<<spEmp.use_count()<<endl;
	PrintEng pEng(spEmp);
	pEng.doPrint();
	cout<<"引用计数:"<<spEmp.use_count()<<endl;
	cout<<"sizeof(spEmp)="<<sizeof(spEmp)<<endl;
	PrintChs pChs(spEmp);
	pChs.doPrint();
	cout<<"引用计数:"<<spEmp.use_count()<<endl;
	cout<<"sizeof(spEmp)="<<sizeof(spEmp)<<endl;
	
	typedef vector<shared_ptr<Employee> > container;
	container vecEmp;
	vecEmp.push_back(spEmp);
	vecEmp.push_back(shared_ptr<Employee>(new Employee("li")));
	cout<<"\n输出vector<Employee>中的元素\n";
	for(container::iterator it=vecEmp.begin();
		it!=vecEmp.end();it++) {
		PrintEng pEng1(*it);
		pEng1.doPrint();
	}

	system("pause");
	return 0;
}
