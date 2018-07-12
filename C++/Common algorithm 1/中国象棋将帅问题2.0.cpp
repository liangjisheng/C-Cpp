#include"stdio.h"
#define HALF_BITS_LENGTH 4		// 一个字节的一半长
#define FULLMASK 255			// 一个字节8为全为1为255
// 左边4位全为1，右边4为全为0
#define LMASK (FULLMASK<<HALF_BITS_LENGTH)
// 右边4位全为1，左边4为全为0
#define RMASK (FULLMASK>>HALF_BITS_LENGTH)
// 将b的右4位设置为n, 1<=n<16
#define RSET(b,n) (b=((LMASK & b) | (n)))
// 将b的左4位设置为n, 1<=n<16
#define LSET(b,n) (b=(n<<HALF_BITS_LENGTH) | (RMASK & b))
// 得到b的右4位的值
#define RGET(b) ((RMASK) & b)
// 得到b的左4位的值
#define LGET(b) (((LMASK) & (b))>>HALF_BITS_LENGTH)
// 将帅移动的行宽度
#define GRIDW 3

int main() {
	unsigned char b;
	for(LSET(b,1);LGET(b)<=GRIDW*GRIDW;LSET( b,(LGET(b)+1) ) ) {
		for(RSET(b,1);RGET(b)<=GRIDW*GRIDW;RSET( b,(RGET(b)+1) ) ) {
			if(LGET(b)%GRIDW != RGET(b)%GRIDW)
				printf("A=%d,B=%d\n",LGET(b),RGET(b));
		}
	}
	return 0;
}
