#include <iostream>
#include <stddef.h>     // for size_t
#include <list>
#include <vector>
#include <stdexcept>    // for invalid_argument
#include <functional>

namespace ProCpp
{
    // 自定义hash函数
    template<typename T>
    class myHash
    {
    public:
        size_t operator()(const T& key) const;
    };

    // Calculate a hash by treating the key as a sequence
    // of bytes and summing the ASCII values of the bytes.
    template<typename T>
    size_t myHash<T>::operator()(const T& key) const
    {
        size_t bytes = sizeof(key);
        size_t res = 0;
        for(size_t i = 0; i < bytes; ++i){
            unsigned char b = *((unsigned char*)&key + i);
            res += b;
        }
        return res;
    }

    // 遗憾的是，对string应用上述哈希方法时，这个函数会计算
    // 整个string对象的哈希，而不是实际文本的哈希。实际文本可能
    // 在堆上，字符串对象只包含一个长度和指向堆上文本的指针
    // 改指针是不同的，即使它指向的文本相同也是如此。这样的
    // 结果就是两个文本相同的string会生成不同的哈希值。
    // 因此，最好专门为string提供hash模板的特化，为包含动态分配
    // 内存的任何类提供泛型模板

    // A hash specialization for strings
    template<>
    class myHash<std::string>
    {
    public:
        size_t operator()(const std::string& key) const;
    };

    // Calculate a hash by summing the ASCII values of all characters
    size_t myHash<std::string>::operator()(const std::string& key) const
    {
        size_t sum = 0;
        for(size_t i = 0; i < key.size(); ++i)
            sum += (unsigned char)key[i];
        return sum;
    }

    // 如果要将其它指针类型或对象用作键，那么必须为这些类型
    // 编写自定义的哈希特化
}


namespace ProCpp
{
    // 自定义哈希容器my_hash_map,支持三类基本操作：插入、删除和
    // 查找。这里的实现忽略了复制和移动构造函数、赋值和移动
    // 赋值运算符.
    template<typename Key, typename T,
        typename Compare = std::equal_to<Key>, typename Hash = myHash<Key> >
    class my_hash_map
    {
        // C++标准只指定了数据结构作为STL容器必须提供的方法和类型别名
        // 容器要求的类型别名
    public:
        using mykey_type = Key;
        using mymapped_type = T;
        using myvalue_type  = std::pair<const Key, T>;
        using myreference = std::pair<const Key, T>&;
        using my_const_reference = const std::pair<const Key, T>&;
        using mysize_type = size_t;
        using mydifference_type = ptrdiff_t;
        using myHash_map_type = my_hash_map<Key, T, Compare, Hash>;

        // Size methods
        bool myempty() const;
        mysize_type mysize() const;
        mysize_type myMax_size() const;

        // Other modifying utilities
        void myswap(my_hash_map& hashIn);

        virtual ~my_hash_map();

        // Throws invalid_argument if the number of buckets is illegal
        explicit my_hash_map(const Compare& comp = Compare(),
                             size_t numBuckets = 101,
                             const Hash& myhash = Hash());

        // Inserts the key/value pair x.
        void myinsert(const myvalue_type& x);

        // Removes the elements with key k, if ti exists
        void myerase(const mykey_type& k);

        // Find returns a pointer to the element with key k.
        // Returns nullptr if no element with that key exists.
        myvalue_type* myfind(const mykey_type& k);
        const myvalue_type* myfind(const mykey_type& k) const;

        // operator[] find the element with key k or inserts an
        // element with that key if none exists yet. Returns a
        // reference to the value corresponding to that key.
        mymapped_type& operator[](const mykey_type& k);

        // print
        void Display() const;
        size_t GetElementNum() const;

    private:
        using ListType = std::list<myvalue_type>;
        std::vector<ListType> mBuckets;
        size_t mSize;       // 保存容器中当前的元素个数
        Compare mComp;
        myHash<Key> mHash;

    private:
        // 根据某个给定键查找元素，bucket表示在哪个桶中
        typename ListType::iterator findElement(const mykey_type& k, size_t& bucket);
    };
}


namespace ProCpp
{
    // 模板类(即自定义哈希容器)的实现
    // Resize mBuckets with the number of buckets.
    template<typename Key, typename T, typename Compare, typename Hash>
    my_hash_map<Key, T, Compare, Hash>::my_hash_map(
            const Compare& comp, size_t numBuckets, const Hash& myhash)
            : mSize(0), mComp(comp), mHash(myhash)
    {
        if(0 >= numBuckets)
            throw std::invalid_argument("Number of buckets must be positive.");
        mBuckets.resize(numBuckets);
    }


    // findElement
    template<typename Key, typename T, typename Compare, typename Hash>
    typename my_hash_map<Key, T, Compare, Hash>::ListType::iterator
    my_hash_map<Key, T, Compare, Hash>::findElement(const mykey_type& k, size_t& bucket)
    {
        // Hash the key to get the bucket
        bucket = mHash(k) % mBuckets.size();

        // Look for the key in the bucket
        for(auto it = std::begin(mBuckets[bucket]);
            it != std::end(mBuckets[bucket]); ++it)
        {
            if(mComp(it->first, k))
                return it;
        }

        return std::end(mBuckets[bucket]);
    }


    // myfind可以实现为findElement的简单包装
    template<typename Key, typename T, typename Compare, typename Hash>
    typename my_hash_map<Key, T, Compare, Hash>::myvalue_type*
    my_hash_map<Key, T, Compare, Hash>::myfind(const mykey_type& k)
    {
        size_t bucket;
        auto it = findElement(k, bucket);
        if(it == std::end(mBuckets[bucket]))
            return nullptr;

        return &(*it);
    }


    // myfind()的const版本使用const_cast,将请求传递给非const版本，
    // 以避免代码重复
    template<typename Key, typename T, typename Compare, typename Hash>
    const typename my_hash_map<Key, T, Compare, Hash>::myvalue_type*
    my_hash_map<Key, T, Compare, Hash>::myfind(const mykey_type& k) const
    {
//        size_t bucket;
//        auto it = findElement(k, bucket);
//        if(it == std::end(mBuckets[bucket]))
//            return nullptr;
//
//        return &(*it);

        return const_cast<my_hash_map<Key, T, Compare, Hash>* >(this)->myfind(k);
    }


    // operator[]
    template<typename Key, typename T, typename Compare, typename Hash>
    T& my_hash_map<Key, T, Compare, Hash>::operator[](const mykey_type& k)
    {
        // Try to find the element. If it does not exist, add a new element.
        myvalue_type* found = myfind(k);
        if(found == nullptr){
            myinsert(std::make_pair(k, T()));
            found = myfind(k);
        }
        return found->second;
    }


    // myinsert()
    template<typename Key, typename T, typename Compare, typename Hash>
    void my_hash_map<Key, T, Compare, Hash>::myinsert(const myvalue_type& x)
    {
        size_t bucket;
        // try to find the element
        // 通过引用返回那个键哈希到的桶，即使没有找到那个键对应的元素也是如此
        auto it = findElement(x.first, bucket);
        if(it != std::end(mBuckets[bucket])){
           return ;     // The element already exists.
        }
        else{
            // we did not find the element, so insert a new one.
            mSize++;
            mBuckets[bucket].push_back(x);
        }
    }


    // myerase
    template<typename Key, typename T, typename Compare, typename Hash>
    void my_hash_map<Key, T, Compare, Hash>::myerase(const mykey_type& k)
    {
        size_t bucket;
        auto it = findElement(k, bucket);
        if(it != std::end(mBuckets[bucket]))
        {
            // The element exists -- erase it.
            mBuckets[bucket].erase(it);
            mSize--;
        }
    }


    // ~my_hash_map()
    template<typename Key, typename T, typename Compare, typename Hash>
    my_hash_map<Key, T, Compare, Hash>::~my_hash_map()
    {
        for(size_t i = 0; i < mBuckets.size(); i++)
            mBuckets[i].clear();

        mBuckets.clear();
    }


    // Display()
    template<typename Key, typename T, typename Compare, typename Hash>
    void my_hash_map<Key, T, Compare, Hash>::Display() const
    {
        std::cout << "Key\tValue" << std::endl;
        for(size_t i = 0; i < mBuckets.size(); i++)
        {
            ListType li = mBuckets[i];
            typename ListType::iterator itBegin = li.begin();
            typename ListType::iterator itEnd = li.end();
            if(itBegin != itEnd)
            {
                std::cout << "list" << i+1 << ": " << std::endl;
                for(; itBegin != itEnd; itBegin++)
                    std::cout << itBegin->first << '\t' << itBegin->second << std::endl;
            }
        }

//        for(typename std::vector<std::list<std::pair<Key, T> > >::iterator it1 = std::begin(mBuckets); it1 != std::end(mBuckets); it1++)
//        {
//            for(typename std::list<std::pair<Key, T> >::iterator it2 = std::begin(it1); it2 != std::end(it1); it2++)
//                std::cout << "key :" << it2->first << ", value :" << it2->second << std::endl;
//        }
    }


    // GetElementNum()
    template<typename Key, typename T, typename Compare, typename Hash>
    size_t my_hash_map<Key, T, Compare, Hash>::GetElementNum() const
    {
        return mSize;
    }
}



int main()
{
    using namespace ProCpp;
    using std::cout;
    using std::endl;
    using std::make_pair;

    // Test my_hash_map<>
    my_hash_map<int, int> my_hash;
    my_hash.myinsert(make_pair(4, 40));
    my_hash.myinsert(make_pair(6, 60));
    cout << "Initial my_hash_map content: " << endl;
    my_hash.Display();

    cout << endl;
    // x will have type my_hash_map<int, int>::my_value_type*
    auto x = my_hash.myfind(4);
    if(x != nullptr)
        cout << "4 maps to " << x->second << endl;
    else
        cout << "can not find 4 in map" << endl;

    my_hash.myerase(4);
    cout << endl;
    cout << "After erase the bucket of the key is 4." << endl;
    my_hash.Display();
    auto x2 = my_hash.myfind(4);
    if(x2 != nullptr)
        cout << "4 maps to " << x2->second << endl;
    else
        cout << "can not find 4 in map" << endl;

    // insert
    cout << endl;
    cout << "insert the key 4 in hash_map." << endl;
    my_hash[4] = 35;
    my_hash[4] = 60;
    my_hash.Display();
    cout << "The number of element is:" << my_hash.GetElementNum() << endl;
    auto x3 = my_hash.myfind(4);
    if(x3 != nullptr)
        cout << "4 maps to " << x3->second << endl;
    else
        cout << "can not find 4 in map." << endl;

    return 0;
}
