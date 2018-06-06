// CountOfObjects
#include <iostream>
using std::cout;
using std::endl;

class CBox;
bool operator>(const double& value, const CBox& box);

class CBox
{
public:
	static int objectCount;
	CBox();
	~CBox();
	explicit CBox(double length, double width = 1.0, double height = 1.0);
	CBox(const CBox& box);
	CBox& operator=(const CBox& box);
	double Volume() const;
	bool Compare(const CBox& box) const;
	bool Compare(CBox* box) const;
	void Show() const;
	void Enlarge(double dMultiple = 1.0);
	CBox operator+(const CBox& box) const;
	CBox operator-(const CBox& box) const;
	bool operator>(const CBox& box) const;
	bool operator>(const double& value) const;
	bool operator<(const CBox& box) const;
	bool operator<(const double& value) const;
	CBox& operator++();		// Prefix
	const CBox operator++(int);		// Postfix
	CBox& operator--();
	const CBox operator--(int);
private:
	double m_Length;
	double m_Width;
	double m_Height;
};

int CBox::objectCount = 0;

CBox::~CBox()
{
	cout << "Destructor called.\n";
}

CBox::CBox()
{
	cout << "\nDefault constructor called.\n";
	m_Length = m_Width = m_Height = 1.0;
	objectCount++;
}

CBox::CBox(double length, double width, double height)
{
	cout << "\nConstruct called.\n";
	m_Length = length;
	m_Width = width;
	m_Height = height;
	objectCount++;
}

CBox::CBox(const CBox& box)
{
	cout << "\nCopy constructor called.\n";
	m_Length = box.m_Length;
	m_Width = box.m_Width;
	m_Height = box.m_Height;
}

CBox& CBox::operator=(const CBox& box)
{
	cout << "\nAssignment constructor called.\n";
	if (this == &box)
		return *this;

	m_Length = box.m_Length;
	m_Height = box.m_Height;
	m_Width = box.m_Width;
	return *this;
}

double CBox::Volume() const
{
	return m_Height * m_Length * m_Width;
}

bool CBox::Compare(const CBox& box) const
{
	return Volume() < box.Volume();
}

bool CBox::Compare(CBox* box) const
{
	if (nullptr == box)
		return 0;
	return Volume() < box->Volume();
}

void CBox::Show() const
{
	cout << "\nThe box attributes is: "
		<< "\nlength = " << m_Length
		<< "\nwidth = " << m_Width
		<< "\nheight = " << m_Height
		<< endl;
}

void CBox::Enlarge(double dMultiple)
{
	m_Length *= dMultiple;
	m_Width *= dMultiple;
	m_Height *= dMultiple;
}

CBox CBox::operator+(const CBox& box) const
{
	CBox tmp;
	tmp.m_Length = m_Length + box.m_Length;
	tmp.m_Height = m_Height + box.m_Height;
	tmp.m_Width = m_Width + box.m_Width;

	return tmp;
}

CBox CBox::operator-(const CBox& box) const
{
	CBox tmp;
	tmp.m_Height = m_Height - box.m_Height;
	tmp.m_Length = m_Length - box.m_Length;
	tmp.m_Width = m_Width - box.m_Width;

	return tmp;
}

bool CBox::operator>(const CBox& box) const
{
	return Volume() > box.Volume();
}

bool CBox::operator>(const double& value) const
{
	return Volume() > value;
}

bool CBox::operator<(const CBox& box) const
{
	return Volume() < box.Volume();
}

bool CBox::operator<(const double& value) const
{
	return Volume() < value;
}

bool operator>(const double& value, const CBox& box)
{
	return value > box.Volume();
}

CBox& CBox::operator++()
{
	++m_Height;
	++m_Length;
	++m_Width;
	return *this;
}

const CBox CBox::operator++(int)
{
	CBox tmp = *this;
	++*this;
	return tmp;
}

CBox& CBox::operator--()
{
	--m_Length;
	--m_Height;
	--m_Width;
	return *this;
}

const CBox CBox::operator--(int)
{
	CBox tmp = *this;
	--*this;
	return tmp;
}

int main(void)
{
	CBox boxes[5];
	CBox match(2.2, 1.1, 0.5);
	CBox cigar(8.0, 5.0, 1.0);
	CBox match_1(match),match_2=match;
	CBox* pB1(&cigar);
	CBox* pB2(nullptr);

	++match;
	match.Show();

	match++;
	match.Show();

	--match_1;
	match_1.Show();

	match_1--;
	match_1.Show();

	cout << "\nNumber of objects (through class) = "
		<< CBox::objectCount;

	cout << "\nNumber of objects (through object) = "
		<< boxes[2].objectCount << endl;

	cout << "\nAddress of cigar is " << pB1 << endl
		<< "Volume of cigar is "
		<< pB1->Volume();

	pB2 = &match;
	if (pB2->Compare(pB1))
		cout << "\nmatch is less than cigar";
	else
		cout << "\nmatch is greater than or equal to cigar";

	pB1 = boxes;
	boxes[2] = match;
	cout << "\nVolume of boxes[2] is " << (pB1 + 2)->Volume()
		<< endl;

	if (match.Compare(match_1))
		cout << "\nmatch is less than match_1";
	else
		cout << "\nmatch is greater than or equal to match_1";
	cout << endl;

	if (match > match_1)
		cout << "\nmatch is greater than match_1";
	else
		cout << "\nmatch is less than or equal to match_1\n";

	cout << "\nVolume of match_2 is " << match_2.Volume() << endl;

	// Output the boxes
	for each (CBox var in boxes)
		var.Show();
	match.Show();
	match_1.Show();
	match_2.Show();
	cigar.Show();

	cigar.Enlarge(2.0);
	cigar.Show();

	CBox match_3(match + match_1);
	match = match + match_1;
	match.Show();

	match = match - match_1;
	match.Show();

	cout << "\nNumber of objects (through class) = "
		<< CBox::objectCount << endl;

	if (match > 50.0)
		cout << "\nmatch is greater than 50.0\n";
	else
		cout << "\nmatch is less than or equal to 50.0\n";

	CBox smallBox(4.0, 2.0, 1.0);
	CBox mediumBox(10.0, 4.0, 2.0);
	CBox aBox, bBox;

	aBox = smallBox + mediumBox;
	cout << "\naBox demensions are ";
	aBox.Show();

	bBox = aBox + smallBox + mediumBox;
	cout << "\nbBox dimension are ";
	bBox.Show();



	cout << "\nNumber of objects (through class) = "
		<< CBox::objectCount << endl;

	system("pause");
	return 0;
}