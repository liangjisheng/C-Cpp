
// 1�����ú���Է�ֹͷ�ļ���һ��Դ�ļ��б��������
// 2������assert�ǽ���Debug�汾�����õĺ꣬���ڼ�鲻�÷����������Ϊ�˲��ٳ����
// Debug��Release�汾������assert��Ӧ�ò����κθ����á�����assert���Ǻ���
// ���Ǻ꣬���԰�assert����һ�����κ�ϵͳ״̬�¶�����ʹ�õİ�ȫ���޺������ֶ�
// 3�����ú����ʵ��һЩ���������������������ȡ��ķǾ�̬��Ա�����ĵ�ַ

#define mymax(a, b) ((a) > (b)) ? (a) : (b)

// ������ʵ�ֱȽϸ��ӣ����ʺ���һ����д�꣬����Էֳɶ�����д������Ҫ����
// ����һ�е�ĩβ��һ��'\',��ʾ��һ����Ȼ�Ǻ궨���һ����
// ���һ�в���'\',��ÿ��'\'���治Ҫ���κ��ַ����ո�Ҳ��Ҫ�������������
#define Compare(a, b) if((a) > (b))\
	printf("The first one is bigger.\n");\
	else\
	printf("The fist one is not bigger.\n");

// ���ܺ���Զ��ж��壬�����ں�չ����ʱ�򣬱�չ���ĺ��Դ��������Ȼ�Ǳ���д��
// һ�е��У���ĳЩ����»������������

// #������������ַ����У�##������������ַ���ϳ��µı�ʶ��

#include <iostream>

using std::cout;
using std::endl;

#define PrintVar(v, index) cout << #v#index" is " << v##index << endl;

int main()
{
	int i1 = 1, i2 = 2, i3 = 3;
	PrintVar(i, 1);
	PrintVar(i, 2);
	PrintVar(i, 3);

	system("pause");
	return 0;
}