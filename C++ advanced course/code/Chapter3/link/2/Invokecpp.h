
// 不加extern "C"就会出现链接错误，找不到定义
extern "C"
{
	void show();
};