
// 根据能力的不同,迭代器被划分为5中不同功能的迭代器
// 1.双向迭代器(Bidirectional iterator): 以递增或递减运算
// list,set,multiset,map,multimap这些容器提供的迭代器都属于此类
// 2.随机存取迭代器(Random access iterator): 随机存取迭代器不但具备
// 双向迭代器的所有属性,还具备随机访问能力.可以对迭代器增加或减少
// 一个偏移量,处理迭代器之间的距离,或者是使用<和>之类的relational(相对关系)
// 操作符来比较两个迭代器.vector,deque,和strings提供的迭代器都属于此类

// 为了写出与容器类型无关的泛型程序代码,最好不要使用随机存取迭代器,
// 例如: 可以在任何容器上使用
// for (iter = coll.begin(); iter != coll.end(); ++iter) {}
// 而下面的代码就不是所有容器都适合了
// for (iter = coll.begin(); iter < coll.end(); ++iter) {}
