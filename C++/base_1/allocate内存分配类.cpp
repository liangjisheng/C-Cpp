#include"iostream"
using namespace std;
#include"memory"
void main(void)
{
	allocator<char> Storage;
	cout<<Storage.max_size()<<endl;
}