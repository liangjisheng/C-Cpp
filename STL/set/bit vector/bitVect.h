//:BITVECT.H--Bit Vector
#ifndef BITVECT_H_
#define BITVECT_H_

class BitVector{
	unsigned char* bytes;
	int Bits,numBytes;
public:
	BitVector();//Dfault:0 size
	//init points to an array of bytes
	//size is measured in byte
	BitVector(unsigned char* init,int size=8);
	//binary is a string of 1s and 0s
	BitVector(char* binary);
	~BitVector();
	void set(int bit);
	void clear(int bit);
	int read(int bit);
	int bits();			//Numbers of bits int the vector
	void bits(int sz);	//Set number of bits
	void print(const char* msg=" ");
};
#endif //BITVECT_H_