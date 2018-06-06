#pragma once

// ���������Ҫ����ͬ���͵Ķ��ڶ�����Щ����Ĺ��캯�������ܴ�
// (���繹�캯��Ҫ�����ܴ�ġ�Ԥ��ָ����С��ʸ�������洢����)��
// ������ȷ����Щ����ķ�����ͷ���һ������ƿ�����Ϳ���Ϊ��Щ����
// ����һ������ػ򻺴档ÿ����������Ҫһ�������ǣ����Դӳ�������
// һ������ʹ�������ʱ����������󷵻س��С������ֻ����һ�ζ���
// ��˹��캯��ֻ����һ�Σ�������ÿ����Ҫʱ�����á���˶��������
// �ڹ��캯����ҪΪ�ܶ�������һЩ���ò����������Ҳ������ͨ��
// ���캯��֮��ķ������ö�������һЩʵ�����еĲ���


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


// ����allocateChunk()��������mChunkSize��Ԫ�أ���ָ��ÿ�������unique_ptr
// ������queue��
template<typename T>
void ObjectPool<T>::allocateChunk()
{
	for (size_t i = 0; i < mChunkSize; ++i)
		mFreeList.emplace(std::make_unique<T>());
}


// ���ؿ����б�ͷ����Ԫ�أ����û�п���Ԫ�أ����ȵ���allocateChunk():
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

