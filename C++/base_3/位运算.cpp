#include"iostream"
#define BIT_MASK(bit_pos) (0x01<<(bit_pos))

int Bit_Reset(unsigned int * val,unsigned char pos) {
	if(pos>=sizeof(unsigned int)*8) return 0;
	*val=(*val & ~BIT_MASK(pos));
	return 1;
}

int main()
{
	unsigned int x=0xffffffff;
	unsigned char y=4;
	Bit_Reset(&x,y);
	std::cout<<std::hex<<x<<std::endl;

	system("pause");
	return 0;
}