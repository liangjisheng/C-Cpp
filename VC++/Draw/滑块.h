class CMy822View : public CView
{
private:
	int hight;		// 曲柄中心距地面的高度
	int radius;		// 半径
	int length;		// 曲柄的长度
	int yo;			// 设定图形在客户区中的位置
	int xo;			
	int Isfirst;	// 第一次绘图的标记
	int t;			// 旋转的角度
	int old_t;		// 旋转的前一次角度
};