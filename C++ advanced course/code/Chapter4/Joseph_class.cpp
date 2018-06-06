
// 面向对象解决约瑟夫环问题

#include <iostream>
#include <cassert>

using std::cout;
using std::endl;
using std::cin;

class Joseph
{
protected:
	int number_of_people;
	int step;
public:
	virtual void CreateOutput() = 0;
	Joseph(int n, int m)
	{
		number_of_people = n;
		step = m;
	}
	virtual ~Joseph() {}
};


class JosephWithArray : public Joseph
{
	int *WorkingArray;
	int NextPeople(int prev);
public:
	JosephWithArray(int n, int m);
	virtual void CreateOutput();
	virtual ~JosephWithArray() { delete [] WorkingArray; }
};


JosephWithArray::JosephWithArray(int n, int m)
	: Joseph(n, m)
{
	WorkingArray = new int [n];
	for(int i = 0; i < n; i++)
		WorkingArray[i] = i + 1;
}


void JosephWithArray::CreateOutput()
{
	int outnum = -1;
	for(int i = 0; i < number_of_people; i++)
	{
		outnum = NextPeople(outnum);
		assert(outnum > -1 && outnum < number_of_people);
		cout << WorkingArray[outnum] << " ";
		WorkingArray[outnum] = 0;
	}
	cout << endl;
}


int JosephWithArray::NextPeople(int prev)
{
	int count = 0;
	int travel = prev;
	int emptyplace = 0;
	while(count < step)
	{
		travel = (travel + 1) % number_of_people;
		if(WorkingArray[travel])
		{
			count++;
			emptyplace = 0;
		}
		else
		{
			emptyplace++;
			if(emptyplace == number_of_people)
				return -1;
		}
	}
	return travel;
}


int main()
{
	int n, m;
	cout << "please input number of people:";
	cin >> n;
	cout << "please input step:";
	cin >> m;
	JosephWithArray obj(n, m);
	obj.CreateOutput();

	system("pause");
	return 0;
}

