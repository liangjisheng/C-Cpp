#include"iostream"
#include"stdlib.h"
#include"cstring"
#include"conio.h"
using namespace std;
struct node{
	char ch;
	struct node *next;
};
typedef struct node *link;
//create_list
link create_list()
{
	link last,p,head;
	char ch;
	cout<<"exit for 0"<<endl;
	head=(link)malloc(sizeof(struct node));
	head->next=NULL;
	last=head;
	cout<<"input a char:";
	cin>>ch;getchar();
	head->ch=ch;head->next=NULL;
	cout<<"input a char:";
	cin>>ch;getchar();
	while(ch!='0'){
		p=(link)malloc(sizeof(struct node));
		p->ch=ch;p->next=NULL;
		last->next=p;last=p;
		cout<<"input a char:";
	    cin>>ch;getchar();
	}
	return head;
}
//print_list
void print_list(link head)
{
	link p=head;
	cout<<"output the char list:"<<endl;
	while(p!=NULL)cout<<p->ch<<" ",p=p->next;
	cout<<endl;
}
//free_listvoid 
void free_list(link head)
{
	link p=head;
	while(p!=NULL)
	{head=head->next;free(p);p=head;}
}
//main
int main()
{
	link head;
	head=create_list();
	print_list(head);
	free_list(head);
	return 0;
}