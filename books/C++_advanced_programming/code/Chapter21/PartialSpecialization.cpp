
// 非类型模板参数不能为对象，甚至不能为double和float，
// 非类型模板参数限定为整型，枚举，指针和引用

// 如果模板类对所有模板参数特例化，则称为完整模板类特例化
// 还可以编写部分特例化的类，这里类允许特例化部分模板参数
// 而不处理其他参数
#include <stddef.h>         // for size_t
#include <string>

template<typename T, size_t WIDTH, size_t HEIGHT>
class Grid
{
public:
    Grid();
    virtual ~Grid();

    void setElementAt(size_t x, size_t y, const T& inElem);
    T& getElementAt(size_t x, size_t y);
    const T& getElementAt(size_t x, size_t y) const;

    size_t getHeight() const { return HEIGHT; }
    size_t getWidth() const { return WIDTH; }

private:
    T mCells[WIDTH][HEIGHT];
};


// 可采用这种方式为char* C风格字符串特例化这个模板类:
// 没有特例化所有模板参数
template<size_t WIDTH, size_t HEIGHT>
class Grid<const char*, WIDTH, HEIGHT>
{
public:
    Grid();
    virtual ~Grid();

    void setElementAt(size_t x, size_t y, const char* inElem);
    const char* getElementAt(size_t x, size_t y) const;

    size_t getHeight() const { return HEIGHT; }
    size_t getWidth() const { return WIDTH; }

private:
    std::string mCells[WIDTH][HEIGHT];
};


// 上面针对char* 的特例化的例子并没有表现出部分特例化的真正威力
// 可以为一个可能的类型子集编写特例化的实现，而不需要为每个类型
// 特例化。例如可以为所有的指针类型编写特例化的Grid()类。这种
// 特例化的复制构造函数和赋值构造函数可对指针指向的对象执行深层
// 复制，而不是保存类中指针的浅表复制。

#include <memory>

template<typename T>
// 下面这行表明，这个类是Grid1模板对所有指针类型的特例化，
// 只有T是指针类型的情况下才提供实现。
class Grid1<T*>
{
public:
    explicit Grid1(size_t inWidth = kDefaultWidth,
                   size_t inHeight = kDefaultHeight);
    Grid1(const Grid1<T*>& src);
    virtual ~Grid1();
    Grid1<T*>& operator=(const Grid1<T*>& src);

    // The Grid1 becomes the owner of the element!
    void setElementAt(size_t x, size_t y, std::unique_ptr<T> inElem);
    T* getElementAt(size_t x, size_t y);
    const T* getElementAt(size_t x, size_t y) const;

    size_t getHeight() const { return mHeight; }
    size_t getWidth() const { return mWidth; }
    static const size_t kDefaultWidth = 10;
    static const size_t kDefaultHeight = 10;

private:
    void initializeCellsContainer();
    void copyFrom(const Grid<T*>& src);
    std::vector<std::vector<std::unique_ptr<T> > > mCells;
    size_t mWidth, mHeight;
};

