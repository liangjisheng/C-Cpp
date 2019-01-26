#include <iostream>
using std::cout;
using std::endl;


class CBox;
bool operator>(const double& value, const CBox& box);
bool operator<(const double& value, const CBox& box);
bool operator==(const double& value, const CBox& box);
CBox operator*(int n,const CBox& box);

class CBox
{
public:
	static int objectCount;
	CBox();
	~CBox();
	CBox(double length, double width = 1.0, double height = 1.0);
	CBox(const CBox& box);
	CBox& operator=(const CBox& box);
	double Volume() const;
	bool Compare(const CBox& box) const;
	bool Compare(CBox* box) const;
	void Show() const;
	double GetLength() const;
	double GetHeight() const;
	double GetWidth() const;
	void Enlarge(double dMultiple = 1.0);
	CBox operator+(const CBox& box) const;
	CBox operator-(const CBox& box) const;
	bool operator>(const CBox& box) const;
	bool operator>(const double& value) const;
	bool operator<(const CBox& box) const;
	bool operator<(const double& value) const;
	bool operator==(const CBox& box) const;
	bool operator==(const double& value) const;
	CBox operator*(double n) const;
	CBox operator/(const CBox& box) const;
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
	cout << "CBox Destructor called. "<<objectCount--<<"\n";
}

CBox::CBox()
{
	cout << "\nCBox Default constructor called. "<<objectCount<<"\n";
	m_Length = m_Width = m_Height = 1.0;
	objectCount++;
}

CBox::CBox(double length, double width, double height)
{
	cout << "\nCBox Construct called. "<<objectCount<<"\n";
	length = length <= 0 ? 1.0 : length;
	width = width <=0 ? 1.0 : width;
	height = height <=0 ? 1.0 : height;

	// Ensure that length >= width
	m_Length = length > width ? length : width;
	m_Width = width < length ? width : length;
	m_Height = height;
	objectCount++;
}

CBox::CBox(const CBox& box)
{
	cout << "\nCBox Copy constructor called. "<<objectCount<<"\n";
	m_Length = box.m_Length;
	m_Width = box.m_Width;
	m_Height = box.m_Height;
}

CBox& CBox::operator=(const CBox& box)
{
	cout << "\nCBox Assignment constructor called. "<<objectCount<<"\n";
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

double CBox::GetHeight() const
{
	return m_Height;
}

double CBox::GetLength() const
{
	return m_Length;
}

double CBox::GetWidth() const
{
	return m_Width;
}

void CBox::Enlarge(double dMultiple)
{
	m_Length *= dMultiple;
	m_Width *= dMultiple;
	m_Height *= dMultiple;
}

CBox CBox::operator+(const CBox& box) const
{
	cout<<"\nCBox add operator function called.\n";
	CBox tmp;
	tmp.m_Length = m_Length + box.m_Length;
	tmp.m_Height = m_Height + box.m_Height;
	tmp.m_Width = m_Width + box.m_Width;

	return tmp;
}

CBox CBox::operator-(const CBox& box) const
{
	cout<<"\nCBox minus operator function called.\n";
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

bool CBox::operator==(const CBox& box) const
{
	return Volume() == box.Volume();
}

bool CBox::operator==(const double& value) const
{
	return Volume() == value;
}

CBox CBox::operator*(double n) const
{
	return CBox(m_Length*n,m_Width*n,m_Height*n);
}

CBox CBox::operator/(const CBox& box) const
{
	return CBox(m_Length / box.m_Length,
		m_Width / box.m_Width,
		m_Height / box.m_Height
		);
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

bool operator>(const double& value, const CBox& box)
{
	return value > box.Volume();
}

bool operator<(const double& value, const CBox& box)
{
	return value < box.Volume();
}

bool operator==(const double& value, const CBox& box)
{
	return value == box.Volume();
}

CBox operator*(int n,const CBox& box)
{
	return box*n;
}


template<typename T,int Size>
class CSample
{
public:
	CSample();
	CSample(const T& value);
	CSample(const T values[],int count);
	bool Add(const T& value);
	T Max() const;
private:
	T m_Values[Size];
	int m_Free;
};

template<typename T,int Size>
CSample<T,Size>::CSample()
{
	m_Free=0;
}

template<typename T,int Size>
CSample<T,Size>::CSample(const T& value)
{
	m_Values[0]=value;
	m_Free=1;			// Next is free
}

template<typename T,int Size>
CSample<T,Size>::CSample(const T values[],int count)
{
	m_Free = count<Size ? count : Size;
	for(int i=0;i<m_Free;i++)
		m_Values[i]=values[i];
}

template<typename T,int Size>
bool CSample<T,Size>::Add(const T& value)
{
	bool ok = m_Free<Size;
	if(ok)
		m_Values[m_Free++]=value;
	return ok;
}

template<typename T,int Size>
T CSample<T,Size>::Max() const
{
	T theMax = m_Free ? m_Values[0] : 0;	// ¿¼ÂÇÊÇ·ñÎª¿Õ
	for(int i=1;i<m_Free;i++)
		if(theMax<m_Values[i])
			theMax = m_Values[i];
	return theMax;
}

int main(void)
{
	CBox boxes[]=
	{
		CBox(8.0,5.0,2.0),
		CBox(5.0,4.0,6.0),
		CBox(4.0,3.0,3.0)
	};

	CSample<CBox,sizeof(boxes)/sizeof(CBox)> myBoxes(boxes,sizeof(boxes)/sizeof(CBox));

	CBox maxBox=myBoxes.Max();
	cout<<"\nThe biggest box has a volume of "
		<<maxBox.Volume()<<endl;

	bool bBig=890.0 < boxes[0];

	system("pause");
	return 0;
}