
// ������Ϊ���֣����ֳ����ͳ�����
// ���ֳ����ֳ�Ϊ���ų����������泣�����ڱ���֮��д�ڴ�������
// �ǲ���Ѱַ�ġ���������ͬ��������һ��������ռ䣬�ǿ���Ѱַ��
// ����define����ĳ���Ҳ�������ֳ���

// ��Щ����ı�ʶ����ͬʱ����������������������Ѱַ��ֵ���ɱ䣬
// ���Կ��Խ�������Ϊ���ֳ�������̬��������ö�ٳ�����ȫ��(��̬����)�׵�ַ
// ���������ǳ����������Ƿ���ֻ���ڴ��У����Ǻ�һ�����һ������
// ������������������ʱ����ܻ�ó������ĵ�ַ��һ������ͨ�������
// ;�������ǽ����޸�

#include <stdio.h>

void ShowValue(const int i)
{
    printf("%d\n", i);
}

int main()
{
    const int j = 5;
    int *ptr = NULL;
    void *p = (void*)&j;
    ptr = (int*)p;
    (*ptr)++;
    // ��ֱ�Ӵ�ӡj����������Ľ����5���Ⲣ����˵����j��ֵû��
    // �仯�����Ǳ������ڴ����Ż��Ĺ������Ǹ��Ѿ���j�滻����
    // ���ֳ���5��Ե��
    //printf("%d\n", j);
    ShowValue(j);

    //system("pause");
    return 0;
}