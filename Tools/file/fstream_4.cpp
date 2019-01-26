#include"iostream"
#include"fstream"//使用文件流
using namespace std;//文件流定义在std命名空间中
int main(int argc,char *argv[])//使用带参数的main函数版本获取命令行信息
{
	char src[260],dest[260],buff[16384];//读写缓冲达到16K
	if(argc<2)cin>>src;   //若无命令行参数，输出源文件名
	else strcpy(src,argv[1]);//否则第一个命令行位源文件名
	if(argc<3)cin>>dest;    //若只有一个命令行参数，输入目的文件名
	else strcpy(dest,argv[2]);//否则第2个命令行参数为目的文件名
	ifstream inf(src,ios_base::in|ios_base::binary);    //二进制读
	if(!inf.fail()){
		ofstream outf(dest,ios_base::out|ios_base::binary);//二进制写
		while(!inf.eof()){                 //是否到源文件末尾
			inf.read(buff,sizeof(buff));
			outf.write(buff,inf.gcount());//按实际读到的字节输入
		}
		outf.close();//关闭目的文件
		inf.close();//关闭源文件
	}
	return 0;
}