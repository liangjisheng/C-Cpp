#pragma once

// 如果程序需要大量同类型的短期对象，这些对象的构造函数开销很大
// (例如构造函数要创建很大的、预先指定大小的矢量，来存储数据)，
// 分析器确认这些对象的分配和释放是一个性能瓶颈，就可以为这些对象
// 创建一个对象池或缓存。每当代码中需要一个对象是，可以从池中请求
// 一个。当使用完对象时，将这个对象返回池中。对象池只创建一次对象
// 因此构造函数只调用一次，而不是每次需要时都调用。因此对象池适用
// 于构造函数需要为很多对象进行一些设置操作的情况，也适用于通过
// 构造函数之外的方法调用对象设置一些实例特有的参数


#include <cstddef>
#include <queue>
#include <stdexcept>
#include <memory>

// Provides an object pool that can be used with any class that provide
// a default constructor.
//
// The object pool constructor creates a pool of objects, which it hands out
// to client when requested via the acquireObject() method.acquireObject()
// returns an Object which is a std::shared_ptr with a custom deleter that
// automatically puts the object back into the object pool when the shared_ptr
// is destroyed and its reference reaches 0.
//
// The constructor and destructor on each object in the pool will be called only
// once each for the lifetime of the program, not once per acquistion and release.
//
// The primary use of an object pool is to avoid creating and deleting objects
// repeatedly. The object poo is most suited to applications that use large
// numbers of objects with expensive constructors for short periods of time, if
// a profile tells you that allocating and deallocating these objects is a 
// bottleneck.


template<typename T>
class ObjectPool
{
public:
	// Creates an object pool with chunkSize objects.
	// Whenever the object pool runs out of objects, chunkSize
	// more objects will be added to the pool. The pool only grows:
	// objects are never removed from the pool(freed), unitl
	// the pool is destroyed.
	// 
	// Throw invalid_argument if chunkSize is 0.
	// Throw bad_alloc if allocation fails.
	ObjectPool(size_t chunkSize = kDefaultChunkSize);
	
	// Prevent assignment and pass-by-value
	ObjectPool(const ObjectPool<T>& src) = delete;
	ObjectPool<T>& operator=(const ObjectPool<T&> rhs) = delete;

	// The type of smart pointer returned by acquiredObject()
	using Object = std::shared_ptr<T>;

	// Reserves an object for use.
	Object acquireObject();

private:
	// mFreeList stores the objects that are not currently in use bu clients.
	std::queue<std::unique_ptr<T> > mFreeList;
	size_t mChunkSize;
	static const size_t kDefaultChunkSize = 10;
	// Allocates mChunkSize new objects and adds them to mFreeList
	void allocateChunk();
};


template<typename T>
ObjectPool<T>::ObjectPool(size_t chunkSize)
{
	if (0 == chunkSize)
		throw std::invalid_argument("chunk size must be positive");
	mChunkSize = chunkSize;
	allocateChunk();
}


// 分配allocateChunk()方法分配mChunkSize个元素，将指向每个对象的unique_ptr
// 保存在queue中
template<typename T>
void ObjectPool<T>::allocateChunk()
{
	for (size_t i = 0; i < mChunkSize; ++i)
		mFreeList.emplace(std::make_unique<T>());
}


// 返回空闲列表头部的元素，如果没有空闲元素，首先调用allocateChunk():
template<typename T>
typename ObjectPool<T>::Object ObjectPool<T>::acquireObject()
{
	if (mFreeList.empty())
		allocateChunk();

	// Move next free object from the queue to a local unique_ptr.
	std::unique_ptr<T> obj(std::move(mFreeList.front()));
	mFreeList.pop();

	// Convert the object point to an Object (a shared_ptr with a custom deleter).
	Object smartObject(obj.release(), [this](T* t) {
		// The custom deleter doesn't acutally deallocate the memory, but simply puts 
		// the object back on the free list.
		mFreeList.push(std::unique_ptr<T>(t));
	} );

	return smartObject;
}

