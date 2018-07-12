
// 组合关系(Composition):部分和整体之间具有相同的生命周期，当整体消亡后，部分也将消亡
// 代码实现时，部分类在整体类的构造函数中被构造，在析构函数中被析构
// 聚合关系(Aggregation):部分和整体之间并没有相同的生命周期，整体消亡后可以独立存在
// 代码实现时，整体类中传入一个部分类的指针，部分类已经在整体类外被构造，因而整体类析构
// 的时候部分类并没有被析构

class Wings
{
public:
	Wings() {}
	~Wings() {}
};

class Goose
{
private:
	Wings wings;
public:
	Goose() {}
	~Goose() {}
};

class GooseGroup
{
public:
	Goose *goose;
public:
	GooseGroup(Goose *goose)
	{
		this->goose = goose;
	}
	~GooseGroup() {}
};

void test()
{
	//上面代码中，Wings类与Goose类就是组合关系，通过设置断点可以看到，当Goose类构造时，
	//先要构造Wings类。而GooseGroup类构造时，传递的参数是已经构造好的Goose类的指针，
	//所以两者的生命周期并不同步，它们是聚合关系
	Goose g;
	Goose *gp = &g;
	GooseGroup gg(gp);
}

