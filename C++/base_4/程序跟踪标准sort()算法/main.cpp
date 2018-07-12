#include"iostream"
#include"algorithm"
#include"trace.h"
using namespace std;

int main(int argc,char *argv[])
{
	SortTracer input[]={7,3,5,6,4,2,0,1,9,8};
	int i;
	for(i=0;i<10;i++)
		cout<<input[i].val()<<" ";
	cout<<endl;

	long created_at_start=SortTracer::creations();
	long max_live_at_start=SortTracer::max_live();
	long assigned_at_start=SortTracer::assignments();
	long compared_at_start=SortTracer::comparisons();

	cerr<<"---[Start std::sort()]---"<<endl;
	sort<>(&input[0],&input[9]+1);
	cerr<<"---[End std::sort()]---"<<endl;
	for(i=0;i<10;i++)
		cout<<input[i].val()<<" ";
	cout<<endl;
	
	cerr<<"std::sort() of 10 SortTracer's was performed by:"<<endl
		<<SortTracer::creations()-created_at_start
		<<"temporary tracers"<<endl<<"up to:"
		<<SortTracer::max_live()
		<<"tracers at the same time("
		<<max_live_at_start<<" before)"<<endl
		<<SortTracer::assignments()-assigned_at_start
		<<" assignmets"<<endl
		<<SortTracer::comparisons()-compared_at_start
		<<" comparisons"<<endl<<endl;
	return 0;
}