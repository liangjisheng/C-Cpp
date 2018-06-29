#include"stdio.h"
#include"stdlib.h"

struct NODE{
	int data;
	struct NODE * next;
};

typedef NODE Node;
typedef NODE * pNode;

pNode create_queue();
void print_queue(pNode queue);
int length_queue(pNode queue);
void free_queue(pNode queue);
pNode push_queue(pNode queue,int num);
pNode pop_queue(pNode queue);

int main()
{
	pNode queue;
	// create_queue
	queue=create_queue();
	printf("The length of the queue is:%d\n",length_queue(queue));
	print_queue(queue);

	// push_queue
	/*int push_num;
	printf("Input the num you want to push:");
	scanf("%d",&push_num);
	queue=push_queue(queue,push_num);
	print_queue(queue);*/

	// pop_queue
	/*getchar();
	char ch;
	printf("Do you want to pop the queue?(y/n):");
	scanf("%c",&ch);
	if(ch=='y' || ch=='Y') {
		queue=pop_queue(queue);
		print_queue(queue);
	}*/

	// free_queue
	free_queue(queue);

	getchar();
	return 0;
}

pNode create_queue() {
	printf("input the data(quit of 0):");
	int num;
	scanf("%d",&num);
	pNode queue=(pNode)malloc(sizeof(Node));
	queue->data=num; queue->next=NULL;
	pNode last=queue,temp;
	int circle=1;
	while(circle) {
		scanf("%d",&num);
		if(num!=0) {
			temp=(pNode)malloc(sizeof(Node));
			temp->data=num;
			temp->next=NULL;
			last->next=temp;
			last=temp;
		}
		else circle=0;
	}

	return queue;
}

void print_queue(pNode queue){
	pNode p=queue;
	while(p!=NULL) {
		printf("%d ",p->data);
		p=p->next;
	}
	printf("\n");
}

int length_queue(pNode queue) {
	int count=0;
	pNode p=queue;
	while(p!=NULL) {
		count++;
		p=p->next;
	}
	return count;
}

void free_queue(pNode queue) {
	pNode p=queue;
	while(p!=NULL) {
		queue=queue->next;
		free(p);
		p=queue;
	}
}

pNode push_queue(pNode queue,int num) {
	pNode p=queue;
	while(p->next!=NULL)
		p=p->next;
	pNode temp;
	temp=(pNode)malloc(sizeof(Node));
	temp->data=num;
	temp->next=NULL;
	p->next=temp;
	return queue;
}

pNode pop_queue(pNode queue) {
	pNode p=queue;
	queue=queue->next;
	free(p);
	return queue;
}