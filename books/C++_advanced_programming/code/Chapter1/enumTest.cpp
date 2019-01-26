#include <iostream>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

// PieceTypeKing的值为 0 ,定义了PieceType类型，并指定了PieceType类型变量可能具有的值 
enum PieceType { PieceTypeKing,PieceTypeQueen,PieceTypeRook,PieceTypePawn };

// 上面给出的枚举并不是强类型的，意味着其并非类型安全。他们总被解释为整形数据，
// 因此可以比较完全不同类型中的枚举值，enum class解决了这些问题
enum class MyEnum{
	EnumValue1,
	EnumValue2 = 10,
	EnumValue3
}; 
// MyEnum 是一个类型安全的枚举，枚举名称不会自动超出封闭的作用域，这表示总是要使用
// 作用域解析操作符
MyEnum value1 = MyEnum::EnumValue1; 

// 默认情况下，枚举值的基本类型是整形，但可以采用以下方式加以改变
enum class MyEnumLong : unsigned long{
	EnumValueLong1,
	EnumValueLong2 = 10,
	EnumValueLong3
}; 

int main(int argc, char** argv) {
	
	PieceType MyPiece;
	MyPiece = PieceTypeKing;
	
	cout<<MyPiece<<endl;
	
	std::cout<<"asdf"<<std::endl;
	
	system("pause");	
	return 0;
}
