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

// Ӣ�Ĵ�ӡԱ����Ϣ
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

// ���Ĵ�ӡԱ����Ϣ
class PrintChs {
private:
	shared_ptr<Employee> m_spEmp;
public:
	PrintChs(shared_ptr<Employee> sp) : m_spEmp(sp) {}
	void doPrint() {
		if(true==(bool)m_spEmp)
			cout<<"Ա����������:"<<m_spEmp->GetName()<<endl;
	}
};

int _tmain(int argc,_TCHAR* argv[])
{
	shared_ptr<Employee> spEmp(new Employee("lishuyu"));
	
	cout<<"sizeof(spEmp)="<<sizeof(spEmp)<<endl;
	cout<<"���ü���:"<<spEmp.use_count()<<endl;
	PrintEng pEng(spEmp);
	pEng.doPrint();
	cout<<"���ü���:"<<spEmp.use_count()<<endl;
	cout<<"sizeof(spEmp)="<<sizeof(spEmp)<<endl;
	PrintChs pChs(spEmp);
	pChs.doPrint();
	cout<<"���ü���:"<<spEmp.use_count()<<endl;
	cout<<"sizeof(spEmp)="<<sizeof(spEmp)<<endl;
	
	typedef vector<shared_ptr<Employee> > container;
	container vecEmp;
	vecEmp.push_back(spEmp);
	vecEmp.push_back(shared_ptr<Employee>(new Employee("li")));
	cout<<"\n���vector<Employee>�е�Ԫ��\n";
	for(container::iterator it=vecEmp.begin();
		it!=vecEmp.end();it++) {
		PrintEng pEng1(*it);
		pEng1.doPrint();
	}

	system("pause");
	return 0;
}
