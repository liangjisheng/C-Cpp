#include"iostream"
#include"cstdlib"
#include"ctime"
#include"fstream"
using namespace std;
int main(int argc,char* argv[]) {
	cout<<"生成一个"<<argv[1]<<"k大小的文本文件"<<endl;
	cout<<"可执行文件路径:"<<argv[0]<<endl;
	ofstream out(argv[2]);
	time_t t;
	srand(unsigned(time(&t)));
	double rd;
	for(int i=0;i<128*atoi(argv[1]);i++) {
		rd=rand()%99+1;
		out.write((char*)(&rd),sizeof(rd));
	}
	return 0;
}