// queue.cpp -- Queue and Customer methods
#include"queue.h"
#include"cstdlib"
#include"ctime"

// Queue methods
Queue::Queue(int qs) : qsize(qs) {
	front=rear=NULL;
	items=0;
}

Queue::~Queue() {
	Node * temp;
	while(front!=NULL) {
		temp=front;
		front=front->Next;
		delete temp;
	}
}

bool Queue::isempty() const 
{ return items==0; }

bool Queue::isfull() const 
{ return items==qsize; }

int Queue::queuecount() const 
{ return items; }

bool Queue::enqueue(const Item & item) {
	if(isfull()) return false;
	Node * add=new Node;
	if(add==NULL) return false;
	add->item=item;
	add->Next=NULL;
	items++;
	if(front==NULL)
		front=add;
	else
		rear->Next=add;
	rear=add;
	return true;
}

bool Queue::dequeue(Item & item) {
	if(isempty()) return false;
	item=front->item;
	Node * de=front;
	front=front->Next;
	delete de;
	items--;
	if(items==0)
		rear=NULL;
	return true;
}

void Customer::set(long when) {
	srand(time(0));
	arrive=when;
	processtime=rand()%3+1;
}