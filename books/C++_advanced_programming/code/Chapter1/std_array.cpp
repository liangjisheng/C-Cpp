#include <iostream>
#include <array>
using namespace std;

// C风格的数组和std::array都具有固定的大小，在运行时数组不会增大或减小 

int main()
{
	array<int,3> arr = {9,8,7};
	cout<<"Array size = "<<arr.size()<<endl;
	cout<<"Element 2 = "<<arr[1]<<endl;
	
	system("pause");
	return 0;
}
