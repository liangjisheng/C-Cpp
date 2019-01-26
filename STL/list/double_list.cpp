#include"stdio.h"
#include"stdlib.h"

struct NODE{
	int data;
	NODE * next;
	NODE * back;
};
typedef NODE Node;
typedef NODE* pNode;

pNode create_list();
void print_list(pNode head);
void free_list(pNode head);
int length_list(pNode head);
pNode delete_list(pNode head,int num);
pNode insert_list(pNode head,int num);
pNode sort_list(pNode head);
pNode swap_list_by_data(pNode head,int num1,int num2);
pNode swap_list_by_index(pNode head,int index1,int index2);
void reverse_list(pNode head);

int main()
{
	pNode head;

	// create and print
	head=create_list();
	print_list(head);
	printf("The length of list is: %d\n",length_list(head));

	// delete
	/*printf("input num you want to delete:");
	int del_num;
	scanf("%d",&del_num);
	if(del_num!=0) {
		head=delete_list(head,del_num);
		print_list(head);
	}*/

	// swap
	/*int num1,num2;
	printf("input tow number to swap:");
	scanf("%d%d",&num1,&num2);
	swap_list_by_data(head,num1,num2);
	print_list(head);*/

	// chear cache
	/*getchar();
	// sort
	char ch;
	printf("Do you want to sort the list:");
	scanf("%c",&ch);
	if(ch=='y' || ch=='Y') {
		printf("\nAfter sort the list:\n");
		sort_list(head);
		print_list(head);
	}*/

	// insert
	/*int insert_num;
	printf("input the insert number:");
	scanf("%d",&insert_num);
	head=insert_list(head,insert_num);
	print_list(head);*/

	// swap_list_by_index
	/*int index1,index2;
	printf("input the index of two number to swap:");
	scanf("%d%d",&index1,&index2);
	swap_list_by_index(head,index1,index2);
	print_list(head);*/

	// reverse_list
	char rev_ch;
	getchar();
	printf("Do you want to reverse list?(y/n)");
	scanf("%c",&rev_ch);
	if(rev_ch=='y' || rev_ch=='Y') {
		printf("reveser list\n");
		reverse_list(head);
		print_list(head);
	}

	// free
	free_list(head);

	return 0;
}

pNode create_list() {
	pNode head,p,last;
	int circle=1,x=0;
	printf("input the data(quit of 0):");
	scanf("%d",&x);
	head=(pNode)malloc(sizeof(Node));
	head->data=x; head->next=NULL; head->back=NULL;
	last=head;
	while(circle) {
		scanf("%d",&x);
		if(x!=0) {
			p=(pNode)malloc(sizeof(Node));
			p->data=x;
			p->next=NULL;
			p->back=last;
			last->next=p;
			last=p;
		}
		else circle=0;
	}
	return head;
}

void print_list(pNode head) {
	pNode p=head;
	while(p!=NULL) {
		printf("%d ",p->data);
		p=p->next;
	}
	printf("\n");
}

void free_list(pNode head) {
	pNode p=head;
	while(head!=NULL) {
		head=head->next;
		free(p);
		p=head;
	}
}

int length_list(pNode head) {
	int count=0;
	while(head!=NULL) {
		count++;
		head=head->next;
	}
	return count;
}

pNode delete_list(pNode head,int num) {
	pNode p=head;
	if(num==head->data) {
		head=head->next;
		head->back=NULL;
		free(p);
	}
	else {
		// pNode pre=p;
		p=p->next;
		while(num!=p->data) {
			// pre=p;
			p=p->next;
		}
		p->next->back=p->back;
		p->back->next=p->next;
		free(p);
	}
	return head;
}

pNode swap_list_by_data(pNode head,int num1,int num2) {
	if(num1==num2) return head;
	else {
		pNode temp=head,p1=NULL,p2=NULL;
		int i;
		for(i=1;i<=length_list(head);i++) {
			if(temp->data==num1)
				p1=temp;
			if(temp->data==num2)
				p2=temp;
			if(p1!=NULL && p2!=NULL)
				break;
			temp=temp->next;
		}
		int data=p1->data;
		p1->data=p2->data;
		p2->data=data;

		return head;
	}
}

pNode sort_list(pNode head) {
	// pNode pre=head;
	pNode p=head->next;
	int len=length_list(head);
	int i,j;
	for(i=1;i<=len;i++) {
		for(j=1;j<=len-i;j++) {
			if(p->back->data > p->data)
				swap_list_by_data(head,p->back->data,p->data);
			// pre=pre->next;
			p=p->next;
		}
		// pre=head;
		p=head->next;
	}
	return head;
}

pNode insert_list(pNode head,int num) {
	sort_list(head);
	pNode temp=(pNode)malloc(sizeof(Node));
	temp->data=num;
	// 在链表头插入元素
	if(head->data > num) {
		temp->next=head;
		head->back=temp;
		temp->back=NULL;
		head=temp;
		return head;
	}
	else {
		// pNode pre=head;
		pNode p=head->next;
		while(p->back->data < num && p->next!=NULL) {
			p=p->next;
			// pre=pre->next;
		}
		// 在链表中间插入元素
		if(p->next!=NULL) {
			temp->next=p;
			temp->back=p->back;
			p->back->next=temp;
			p->back=temp;
			// pre->next=temp;
		}
		// 在链表尾插入元素
		else {
			p->next=temp;
			temp->next=NULL;
			temp->back=p;
		}
		return head;
	}
}

void reverse_list(pNode head) {
	int len=length_list(head);
	int i;
	for(i=1;i<=len/2;i++) {
		swap_list_by_index(head,i,len-(i-1));
	}
}

pNode swap_list_by_index(pNode head,int index1,int index2) {
	if(index1==index2) return head;
	else {
		pNode temp=head,p1=NULL,p2=NULL;
		int i;
		for(i=1;i<=length_list(head);i++) {
			if(i==index1)
				p1=temp;
			if(i==index2)
				p2=temp;
			if(p1!=NULL && p2!=NULL)
				break;
			temp=temp->next;
		}
		int data=p1->data;
		p1->data=p2->data;
		p2->data=data;

		return head;
	}
}