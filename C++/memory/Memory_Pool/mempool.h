
// 内存池适用来改善标准的new/delete内存管理机制可能造成的运行效率低下的问题的一种技术
// 在C++中，如果频繁的申请大小不同的对象，可能在堆空间造成很多碎片，从而印影响动态内存
// 的申请效率，同时，用于通用的内存管理机制要考虑很多复杂的具体情况(如应付多线程环境等)
// 难以对算法做有效的优化，所以在一些特殊场合，利用一些简化条件，就能够在一定程度上提高
// 内存管理的效率
// 经典的内存池技术(Memory Pool)技术，是一种用于分配大量大小相同的小对象的技术。通过
// 该技术可以极大的加快内存分配/释放过程。既然是针对特定对象对象的内存池，所以内存池
// 一般设置为类模板，根据不同的对象的大小进行实例化
// 经典的内存池的内部结构是这样的：先申请一块连续的内存空间(Memory Block),该空间能容纳
// 一定数量的对象，每个对象连同一个指向下一个对象的指针一起构成一个内存节点(Memory Node)
// 各内存节点之间通过指针形成一个链表，链表当中的每一个节点都是一块可供分配的内存空间
// 某个内存节点一旦分配出去，就将从链表中去除；而一旦释放了某个内存节点的空间，又会将
// 该节点重新加入自由内存节点链表。如果一个内存块中的所有内存节点已经分配完毕，而程序
// 继续申请新的对象空间，则会在次申请一个内存块，以便从内存块中分割出新的内存节点。
// 所以内存池类模板有这样几个数据成员：两个常量，MemBlockSize(内存块的大小)、ItemSize
// (对象的大小)，以及两个指针变量pMemBlockHeader(指向内存块链表的第一个节点)
// pFreeNodeHeader(指向内存节点链表的第一个节点)，开始两个指针均为空，
// 一下提供了经典内存池的一种实现方案


// ObjectSize代表实际申请的对象的大小
// NumofObjects代表每个内存块所能容纳的对象个数
template<int ObjectSize, int NumofObjects = 20>
class MemPool
{
private:
	const int MemBlockSize;		// 每个内存块的大小
	const int ItemSize;			// 每个内存节点的大小
	struct _FreeNode
	{
		_FreeNode *pNext;
		char data[ObjectSize];
	};
	struct _MemBlock
	{
		_MemBlock *pNext;
		_FreeNode data[NumofObjects];
	};
	_MemBlock *pMemBlockHeader;
	_FreeNode *pFreeNodeHeader;
public:
	MemPool() : ItemSize(ObjectSize + sizeof(_FreeNode*)),
		MemBlockSize(sizeof(_MemBlock*) + NumofObjects * (ObjectSize + sizeof(_FreeNode*)))
	{
		pMemBlockHeader = NULL;
		pFreeNodeHeader = NULL;
	}
	~MemPool()
	{
		_MemBlock *ptr;
		while(pMemBlockHeader)
		{
			ptr = pMemBlockHeader;
			delete pMemBlockHeader;
			pMemBlockHeader = ptr;
		}
	}
	void* malloc();
	void free(void*);
};

// 对特定对象而言，内存池中内存块的大小是固定的，内存节点的大小也是规定的，内存块
// 在申请之初就被划分为多个内存节点，每个Node的大小为ItemSize(对象的大小加上一个指针)
// 刚开始时所有的节点都是自由的，他们被串成链表
// 指针变量pMemBlockHeader是把所有申请的内存块(Memory Block)串成一个链表，以便通过它
// 可以释放所有申请的内存，pFreeNodeHeader变量则是把所有的自由内存节点(Free Node)串
// 成一个串。pFreeNodeHeader为空表明已经没有可用的自由内存节点，必须申请新的内存块

// 申请过程如下，在自由内存节点链表(pFreeNodeHeader)非空的情况下，malloc过程只是从
// 链表中摘下自由内存节点链表的头一个节点，然后把链表头指针移动到下一个节点上去，
// 否则，意味着需要一个新的内存块(Memory Block),这个过程需要将新申请的内存块切割成
// 多个内存节点，并把他们串起来，内存池技术的主要开销就在这里
template<int ObjectSize, int NumofObjects /* = 20*/>
void* MemPool<ObjectSize, NumofObjects>::malloc()
{
	if(pFreeNodeHeader == NULL)
	{
		_MemBlock *pNewBlock = new _MemBlock;
		pNewBlock->data[0].pNext = NULL;
		for(int i = 1; i < NumofObjects; ++i)
			pNewBlock->data[i].pNext = &pNewBlock->data[i - 1];
		pFreeNodeHeader = &pNewBlock->data[NumofObjects - 1];
		pNewBlock->pNext = pMemBlockHeader;
		pMemBlockHeader = pNewBlock;
	}
	void *pFreeNode = pFreeNodeHeader;
	pFreeNodeHeader = pFreeNodeHeader->pNext;
	return pFreeNode;
}

// 释放的过程，只要把被释放的节点重新插入到自由内存节点链表的开头即可，最后被释放的
// 节点就是下一个即将被分配的节点，内存池技术申请/分配内存的速度很快，其内存分配过程
// 多数情况下复杂度为O(1),主要开销在pFreeNodeHeader为空时需要生成新的内存块，内存
// 释放过程的复杂度为O(1)
template<int ObjectSize, int NumofObjects /* = 20*/>
void MemPool<ObjectSize, NumofObjects>::free(void* p)
{
	// 释放p指向的内存块并不是真正的释放p，而只是将p指向的内存块放入内存池中
	// 空闲的内存，下次分配对象的时候会首先使用刚释放掉的这块内存
	_FreeNode* pNode = (_FreeNode*)p;
	pNode->pNext = pFreeNodeHeader;
	pFreeNodeHeader = pNode;
}

// 以上内存池方案并不完美，比如：只能单个单个申请对象空间，不能申请对象数组
// 内存池中的内存块的个数只能越来越大，不能减小，现在有很多改进方案

