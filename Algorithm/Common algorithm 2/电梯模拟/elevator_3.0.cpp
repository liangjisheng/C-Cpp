//电梯系统，使n个人的等待时间最小
#include"iostream"
#include"vector"
#include"ctime"
#include"algorithm"
#include"cstdlib"
using namespace std;

int n,N;//n表示总共有n个人坐电梯，N表示楼层总共有N层
int AllWaitTime;//表示n个人总共等待时间
int AFloorRunTime=3;//表示电梯每层运行时间，应为一常数，待定
int StopTime=5;//表示电梯在该层停留时间，应为一常数，待定
int MaxLoadNum=13;//电梯最大所载人数
vector<int> ArriveTime;//n个人到达时间
vector<int> ArriveFloor;//每个人随机到达的层数，由rand函数求出
vector<int> WaitTime;//每个人所等待时间
int EleRunTime;//电梯每次运行时间
vector<int> EleLoadNum;//电梯每次所载人数
//vector<int> EleToFloorOne;//电梯从往上走到再回到一楼的时间

//求最大楼层数
int maxf(vector<int> &v)
{
	int max=v[0];
	for(int i=1;i<v.size();i++)
	{if(v[i]>max)max=v[i];}
	return max;
}
//查找是否有相同的数
int FIND(vector<int> &df,int data)
{
	for(int i=0;i<df.size();i++)
		if(data==df[i])return i;
    return df.size();
}
//求去往不同楼层的人数
int DifferentFloorNum(vector<int> &v)
{
	vector<int> df;
	int find,i;
	for(i=0;i<v.size();i++){
		find=FIND(df,v[i]);
		if(find==df.size())
			df.push_back(v[i]);
	}
	return df.size();
}

//求每个人等待时间
void waittime()
{
	int i,wt;//wt表示当前人的等待时间
	WaitTime.push_back(0);
	EleRunTime=0;
	int internal;//internal表示正在等电梯的人和正在坐电梯的人到达时间之差
//	int count;//count表示此刻在一楼的人数，就是最早到达和最晚到达，两人到达时间
	          //之差小于电梯上次运行时间，也即电梯下次运行时所载人数
	vector<int> CurEleArrFloor;//记录当前电梯所要到达的层数
	int StopTimeNum;//记录电梯停留的次数，也就是CurEleArrFloor中有多少个不同的数
	int MaxFloor;//记录CurEleArrFloor中最大的数，求此次电梯的运行时间
	i=0;
	CurEleArrFloor.push_back(ArriveFloor[i]);
	while(ArriveTime[i+1]==ArriveTime[i]){//找到此刻同一时间到达的人，直到不是同一时间到达
		WaitTime.push_back(0);
		CurEleArrFloor.push_back(ArriveFloor[i+1]);
		i++;
	}
	i++;
	MaxFloor=maxf(CurEleArrFloor);//求最大楼层数
	StopTimeNum=DifferentFloorNum(CurEleArrFloor);//求去往不同楼层的人数
	EleRunTime=2*AFloorRunTime*MaxFloor+StopTime*StopTimeNum;
	CurEleArrFloor.clear();//清空向量，为下一次做准备
	for(;i<n-1;)//n表示总共的人数，n为全局变量，i表示此刻正在坐电梯的人
		//上一行代码中n-1出错了
	{
		//count=1;
		internal=ArriveTime[i]-ArriveTime[i-1];
		wt=EleRunTime-internal;//wt表示当前等待时间
		CurEleArrFloor.push_back(ArriveFloor[i]);
		if(wt>=0)//第i个人的等待时间
			WaitTime.push_back(wt);
		else
			WaitTime.push_back(0);
		//找到此刻同一时间到达的人，直到不是同一时间到达
		while((ArriveTime[i+1]==ArriveTime[i])&&(i+1<n)){
			if(wt>=0)
				WaitTime.push_back(wt);
			else
				WaitTime.push_back(0);
		    CurEleArrFloor.push_back(ArriveFloor[i+1]);
		    i++;
		}
		i++;
		for(;i<n-1;){//n-1出错了
			internal=ArriveTime[i]-ArriveTime[i-1];
			wt=EleRunTime-internal;
			if(wt>=0){
				WaitTime.push_back(wt);
				CurEleArrFloor.push_back(ArriveFloor[i]);
				i++;
			}
		}
		i++;
		MaxFloor=maxf(CurEleArrFloor);//求最大楼层数
		StopTimeNum=DifferentFloorNum(CurEleArrFloor);//求去往不同楼层的人数
		EleRunTime=2*AFloorRunTime*MaxFloor+StopTime*StopTimeNum;//电梯运行时间
		CurEleArrFloor.clear();//清空向量，为下一次做准备
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
//template<typename Container>
void Display(ostream & out,vector<int> &v)
{
	for(int i=0;i<v.size();i++){
		out<<v[i]<<" ";
		if((i+1)%10==0)//每行输出10个到达时间
			out<<endl;
	}
	out<<endl;
}

//输出10个人到达的层数
void Display_Floor(vector<int> &v)
{
	for(int i=0;i<v.size();i++){
		cout<<v[i]+1<<" ";
		if((i+1)%10==0)//每行输出10个到达层数
			cout<<endl;
	}
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
		Display_Floor(ArriveFloor);//输出随机到达序列

	cout<<endl;
	cout<<"电梯在每层运行的时间为:"<<AFloorRunTime<<"秒"<<endl;
	cout<<"电梯在每层停留的时间为:"<<StopTime<<"秒"<<endl;
	waittime();//求每个人所等待的时间
	SumWaitTime(WaitTime);//WaitTime为等待时间序列
	cout<<"每人的等待时间:"<<endl;
	Display(cout,WaitTime);//输出每个人的等待时间
//	cout<<"电梯每次运行时间为:"<<endl;
//	Display(cout,EleRunTime);//输出每次电梯的运行时间
	cout<<"总共等待时间为:"<<AllWaitTime<<"秒"<<endl;
	return 0;
}