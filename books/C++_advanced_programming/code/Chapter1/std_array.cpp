#include <iostream>
#include <array>
using namespace std;

// C���������std::array�����й̶��Ĵ�С��������ʱ���鲻��������С 

int main()
{
	array<int,3> arr = {9,8,7};
	cout<<"Array size = "<<arr.size()<<endl;
	cout<<"Element 2 = "<<arr[1]<<endl;
	
	system("pause");
	return 0;
}
