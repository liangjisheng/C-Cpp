#include"iosteram"
using namespace std;

int main()
{
	int * pInt=NULL;
	float * pFloat=NULL;
	void* pVoid;
	pVoid=pInt;
	pVoid=pFloat;
	pFloat=(float*)pVoid;

	int nVal1,nVal2;
	double dResult=((double)nVal1)/nVal2;
	double dresult_1=static_cast<double>(nVal1)/nVal2;

	system("pause");
	return 0;
}