#include <iostream>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

// PieceTypeKing��ֵΪ 0 ,������PieceType���ͣ���ָ����PieceType���ͱ������ܾ��е�ֵ 
enum PieceType { PieceTypeKing,PieceTypeQueen,PieceTypeRook,PieceTypePawn };

// ���������ö�ٲ�����ǿ���͵ģ���ζ���䲢�����Ͱ�ȫ�������ܱ�����Ϊ�������ݣ�
// ��˿��ԱȽ���ȫ��ͬ�����е�ö��ֵ��enum class�������Щ����
enum class MyEnum{
	EnumValue1,
	EnumValue2 = 10,
	EnumValue3
}; 
// MyEnum ��һ�����Ͱ�ȫ��ö�٣�ö�����Ʋ����Զ�������յ����������ʾ����Ҫʹ��
// ���������������
MyEnum value1 = MyEnum::EnumValue1; 

// Ĭ������£�ö��ֵ�Ļ������������Σ������Բ������·�ʽ���Ըı�
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
