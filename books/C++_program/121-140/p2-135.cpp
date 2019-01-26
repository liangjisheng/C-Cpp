#include<iostream.h>
//����ڵ㣨���ݶ��󣩵Ľӿ�
class Node
{
    //����list��Ϊ�������Ԫ��
    friend class list;
//˽�г�Ա 
private:              
    int Data;       //�ڵ�����
    Node *previous; //ǰ��ָ��
    Node *next;     //���ָ��
};

//����˫������list�Ľӿ�����
class list
{
//˽�г�Ա 
private:     
    Node *Head;    //����ͷָ��
    Node *Tail;    //����βָ��
//����ӿں���
public:
    //���캯��
    list();
    //��������
    ~list();
    //������β���������
    void Build_HT(int Data);
    //������ǰͷ�������
    void Build_TH(int Data);
    //��ͷ��β��ʾ����
    void list::Display_HT();
    //��β��ͷ��ʾ����
    void list::Display_TH();
    //��������ȫ������
    void Clear();
};

//main()��������˫������
int main(void)
{
    list list1;
    int i;
   
    //��β�������
    cout<<"Add to the back of the list1:"<<endl;
    for (i=1;i<=20;i=i+2) {
        list1.Build_HT(i);
        cout<<i<<" ";
    }
    cout<<endl;

    //��ͷ�������
    cout<<"Add to the front of the list1:"<<endl;
    for (i=0;i<=20;i=i+2) {
        list1.Build_TH(i);
        cout<<i<<" ";
    }
    cout<<endl;

    //��ʾ����
    list1.Display_HT();
    list1.Display_TH();

    return 0;
}
//list�ຯ���Ķ���
//���캯���Ķ���
list::list()
{
     //��ֵ
     Head=0;
     Tail=0;
}
//���������Ķ���
list::~list()
{
    Clear(); 
}
//������β���������
void list::Build_HT(int Data)
{
    Node *Buffer;

    Buffer=new Node;
    Buffer->Data=Data;
    if(Head==0)
    {
        Head=Buffer;
        Head->next=0;
        Head->previous=0;
    Tail=Head;
    }
    else
    {
        Tail->next=Buffer;
        Buffer->previous=Tail;
    Buffer->next=0;
        Tail=Buffer;
    }
}
//������ǰͷ�������
void list::Build_TH(int Data)
{
    Node *NewNode;
    NewNode=new Node;
    NewNode->Data=Data;

    if(Tail==0)
    {
        Tail=NewNode;
    Tail->next=0;
        Tail->previous=0;
        Head=Tail;
    }
    else
    {
        NewNode->previous=0;
        NewNode->next=Head;
        Head->previous=NewNode;
        Head=NewNode;
    }
}
//��ͷ��β��ʾ����
void list::Display_HT()
{
    Node *TEMP;
    TEMP=Head;
    cout<<"Display the list from Head to Tail:"<<endl;
    while(TEMP!=0)
    {
        cout<<TEMP->Data<<" ";
        TEMP=TEMP->next;
    }
    cout<<endl;
}
//��β��ͷ��ʾ����
void list::Display_TH()
{
    Node *TEMP;
    TEMP=Tail;
    cout<<"Display the list from Tail to Head:"<<endl;
    while(TEMP!=0)
    {
        cout<<TEMP->Data<<" ";
        TEMP=TEMP->previous;
    }
    cout<<endl;
}
//��������ȫ������
void list::Clear()
{
    Node *Temp_head=Head;

    if (Temp_head==0) return;
    do
    {
        Node *TEMP_NODE=Temp_head;
        Temp_head=Temp_head->next;
        delete TEMP_NODE;
    }
    while (Temp_head!=0);
}
