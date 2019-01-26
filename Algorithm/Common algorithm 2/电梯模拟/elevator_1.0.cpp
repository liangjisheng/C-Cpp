//电梯系统，使n个人的等待时间最小
#include"iostream"
#include"vector"
#include"ctime"
#include"algorithm"
#include"cstdlib"
using namespace std;

int n,N;//n表示总共有n个人坐电梯，N表示楼层总共有N层
int AllWaitTime;//表示n个人总共等待时间
int AFloorRunTime=4;//表示电梯每层运行时间，应为一常数，待定
int Stoptime=5;//表示电梯在该层停留时间，应为一常数，待定
int MaxLoadNum=13;//电梯最大所载人数
vector<int> ArriveTime;//n个人到达时间
vector<int> ArriveFloor;//每个人随机到达的层数，由rand函数求出
vector<int> WaitTime;//每个人所等待时间
vector<int> EleRunTime;//电梯每次运行时间
//vector<int> EleRunNum;//电梯此时所载人数，也就是同一时间多到达的人数
//vector<int> EleToFloorOne;//电梯从往上走到再回到一楼的时间

//求每个人等待时间
void waittime()
{
	int i;//wt用于记录当前等待时间
	WaitTime.push_back(0);
	if(ArriveFloor[0]==0)//设置电梯第一次运行的时间
		EleRunTime.push_back(0);
	else 
		EleRunTime.push_back(2*AFloorRunTime*ArriveFloor[0]+Stoptime);
	int internal;//表示前后两人到达时间之差
	for(i=0;i<n-1;i++)//n表示总共的人数，n为全局变量
	{
		internal=ArriveTime[i+1]-ArriveTime[i];
		if(internal>=EleRunTime[i])
		{
			WaitTime.push_back(0);//第i+1个人的等待时间为0//设置电梯下一次的运行时间
			if(ArriveFloor[i+1]==0)//设置电梯下一次运行时间
				EleRunTime.push_back(0);
			else 
				EleRunTime.push_back(2*AFloorRunTime*ArriveFloor[i+1]+Stoptime);
		}
		else
		{
			WaitTime.push_back(EleRunTime.back()-internal);
			if(ArriveFloor[i+1]==0)//设置电梯下一次运行时间
				EleRunTime.push_back(0);
			else 
				EleRunTime.push_back(2*AFloorRunTime*ArriveFloor[i+1]+Stoptime);
		}
	}
}
//求总共等待时间模板
template<typename Container>
void SumWaitTime(const Container &v)
{
	for(int i=0;i<v.size();i++)
		AllWaitTime+=v[i];
}

//输出模板
template<typename Container>
void Display(ostream & out,const Container &v)
{
	for(int i=0;i<v.size();i++){
		out<<v[i]<<" ";
		if((i+1)%10==0)//每行输出10个到达时间
			out<<endl;
	}
	out<<endl;
}

//顾客到达时间的生成
//模拟n个人所到达的时间，在0到150的范围内，就是两分钟半时间内n个人所到达的时间
void RandArriveTime()
{
	cout<<"请输入总共坐电梯的人数:";
	cin>>n;
	int i,t;//t用于暂存当前时间
	for(i=0;i<n;i++){
		t=rand()%150;
		ArriveTime.push_back(t);
	}
	//使用标准算法里的sort对生成的随机到达时间排序
	sort(ArriveTime.begin(),ArriveTime.end());
}

//n个人随机到达的层数的生成
void RandArriveFloor()
{
	cout<<"请输入楼层共有多少层:";
	cin>>N;
	int i,floor;//floor用于暂存当前的层数
	for(i=0;i<n;i++){
		floor=rand()%N;
		ArriveFloor.push_back(floor);
	}
}
//主函数
int main()
{
	srand(time(0));
	RandArriveTime();//随机生成到达时间
	char ch;//ch用于判断是否输出随机生成的数据
	cout<<"请问您是否要输出n个人到达的时间(y/n)?";
	cin>>ch;
	if(ch=='y'||ch=='Y')
		Display(cout,ArriveTime);//输出随机到达时间
	RandArriveFloor();//随机生成到达序列
	cout<<"请问您是否要输出n个人到达的层数(y/n)?";
	cin>>ch;
	if(ch=='y'||ch=='Y')
		Display(cout,ArriveFloor);//输出随机到达序列

	cout<<"电梯在每层运行的时间为:"<<AFloorRunTime<<"秒"<<endl;
	cout<<"电梯在每层停留的时间为:"<<Stoptime<<"秒"<<endl;
	waittime();//求每个人所等待的时间
	SumWaitTime(WaitTime);//WaitTime为等待时间序列
	cout<<"每人的等待时间:"<<endl;
	Display(cout,WaitTime);//输出每个人的等待时间
	cout<<"电梯每次运行时间为:"<<endl;
	Display(cout,EleRunTime);//输出每次电梯的运行时间
	cout<<"总共等待时间为:"<<AllWaitTime<<"秒"<<endl;
	return 0;
}