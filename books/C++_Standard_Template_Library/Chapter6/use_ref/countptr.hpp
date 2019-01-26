
// 在STL提供引用语义时，需要采用智能型指针，避免可能的错误，这个有一个解决办法：
// 对指针所指的对象采用reference counting(引用计数)智能型指针
// 只有当指向同一对象的最后一个智能型指针被摧毁，其所指对象才会被删除

#ifndef _COUNTED_PTR_HPP_
#define _COUNTED_PTR_HPP_

/* class for counted reference semantics
 * deletes the object to which it refers when the last CountedPtr
 * that refers to it is destroyed
*/
template<class T>
class CountedPtr
{
private:
	T *ptr;			// pointer to the value
	long *count;	// shared number of owners

public:
	// initialize pointer with existing pointer
	// requires that the pointers p is a return value of new
	explicit CountedPtr(T *p = NULL) : ptr(p), count(new long(1)) {}

	// copy pointer (one more owner)
	// throw()表示这个函数不会跑出任何异常
	CountedPtr(const CountedPtr<T>& p) throw()
		: ptr(p.ptr), count(p.count) { ++*count; }

	// destructor (delete value if this was the last owner)
	~CountedPtr() throw() { dispose(); }

	// assignment(unshare old and share new value)
	CountedPtr<T>& operator =(const CountedPtr<T>& p) throw()
	{
		if (this != &p)
		{
			dispose();
			ptr = p.ptr;
			count = p.count;
			++*count;
		}
		return *this;
	}

	// access the value to which the pointer refers
	T& operator*() const throw() { return *ptr; }

private:
	void dispose()
	{
		if (--*count == 0)
		{
			delete count;
			delete ptr;
		}
	}
};

#endif // _COUNTED_PTR_HPP_