#include"iostream"
#include"tracer.h"
#include"algorithm"

int main()
{
	SortTracer input[]={7,3,5,6,4,2,0,1,9,8};
	//输出初始值
	int i;
	for(i=0;i<10;i++)
		cerr<<input[i].val()<<' ';
	cerr<<endl;

	// 存取初始状态
	/*long created_at_start=SortTracer::creations();
	long max_live_at_start=SortTracer::max_live();
	long assigned_at_start=SortTracer::assignments();
	long compared_at_start=SortTracer::comparisions();

	cerr<<"---[ Start std::sort() ]------------------------\n";
	sort(&input[0],&input[9]+1);
	cerr<<"---[ End std::sort() ]--------------------------\n";

	// 确认结果
	for(i=0;i<10;i++)
		cerr<<input[i].val()<<' ';
	cerr<<endl;
	cerr<<endl;

	// 输出报告
	cerr<<"std::sort() of 10 SortTracer's"
		<<" was performed by:\n"
		<<SortTracer::creations()-created_at_start
		<<" temporary tracers\n"
		<<"up to "<<SortTracer::max_live()
		<<" tracers at the same time ("
		<<max_live_at_start<<" before)\n"
		<<SortTracer::assignments()-assigned_at_start
		<<" assignments\n"
		<<SortTracer::comparisions()-compared_at_start
		<<" comparisons\n\n";*/

	system("pause");
	return 0;
}
