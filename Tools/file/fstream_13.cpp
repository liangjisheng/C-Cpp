/*#include"iostream"
#include <fstream>
using namespace std;
struct student
{
   char name[20];
   int num;
   int age;
   char sex;
};
int main(int argc,char *argv[])
{
   student stud[3]={"Li",1001,18,'f',"Fun",1002,19,'m',"Wang",1004,17,'f'};
   ofstream outfile("stud.dat",ios::binary);
   if(!outfile)
   {
      cerr<<"open error!"<<endl;
      abort( );//创建文件失败，退出程序
   }
   for(int i=0;i<3;i++)
      outfile.write((char*)&stud[i],sizeof(stud[i]));
   outfile.close( );
   return 0;
}*/
#include"iostream"
#include"string"
#include <fstream>
using namespace std;
struct student
{
   string name;
   int num;
   int age;
   char sex;
};
int main(int argc,char *argv[])
{
   student stud[3];
   int i;
   ifstream infile("stud.dat",ios::binary);
   if(!infile)
   {
      cerr<<"open error!"<<endl;
      abort( );//打开文件失败，退出程序
   }
   for(i=0;i<3;i++)
	   infile.read((char*)&stud[i],sizeof(student));
   infile.close( );
   for(i=0;i<3;i++)
   {
      cout<<"NO."<<i+1<<endl;
      cout<<"name:"<<stud[i].name<<endl;
      cout<<"num:"<<stud[i].num<<endl;
      cout<<"age:"<<stud[i].age<<endl;
      cout<<"sex:"<<stud[i].sex<<endl<<endl;
   }
   return 0;
}