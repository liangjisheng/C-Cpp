// queuetp.h -- template class queue
#ifndef QUEUETP_H_
#define QUEUETP_H_

template<typename Item>
class Queue {
private:
	enum { SIZE =10 };
	class Node {
	private:
		Item item;
	public:
		Node * Next;
		Node(const Item & i,Node * next=NULL)
			: item(i),Next(next) {}
		Item value() const { return item; }
	};
	Node* front;	// first pointer of Node
	Node * rear;	// last pointer of Node
	int items;		// current Nodes numbers 
	int maxsize;	// maximum Nodes numbers
public:
	Queue(int ms = SIZE);
	virtual ~Queue();
	int size() const { return items; }
	int maxitems() const { return maxsize; }
	bool isempty() const { return items==0 ;}
	bool isfull() const { return items==maxsize; }
	bool enqueue(const Item &);
	bool dequeue(Item &);
};

template<typename Item>
Queue<Item>::Queue(int ms) : maxsize(ms) 
{ items=0; front=rear=NULL; }

template<typename Item>
Queue<Item>::~Queue() {
	Node *p=front;
	while(front!=NULL) {
		front=front->Next;
		delete p;
		p=front;
	}
}

template<typename Item>
bool Queue<Item>::enqueue(const Item & i) {
	if(isfull())
		return false;
	else {
		Node *p=new Node(i);
		if(p==NULL)
			return false;
		if(front==NULL)
			front=rear=p;
		else {
			rear->Next=p;
			rear=p;
		}
		items++;
		return true;
	}
}

template<typename Item>
bool Queue<Item>::dequeue(Item & i) {
	if(front==NULL)
		return false;
	Node * p=front;
	front=front->Next;
	i=p->value();
	items--;
	delete p;
	if(items==0)
		rear=NULL;
	return true;
}

#endif