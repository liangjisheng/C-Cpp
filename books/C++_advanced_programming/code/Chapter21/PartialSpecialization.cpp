
// ������ģ���������Ϊ������������Ϊdouble��float��
// ������ģ������޶�Ϊ���ͣ�ö�٣�ָ�������

// ���ģ���������ģ����������������Ϊ����ģ����������
// �����Ա�д�������������࣬��������������������ģ�����
// ����������������
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


// �ɲ������ַ�ʽΪchar* C����ַ������������ģ����:
// û������������ģ�����
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


// �������char* �������������Ӳ�û�б��ֳ���������������������
// ����Ϊһ�����ܵ������Ӽ���д��������ʵ�֣�������ҪΪÿ������
// ���������������Ϊ���е�ָ�����ͱ�д��������Grid()�ࡣ����
// �������ĸ��ƹ��캯���͸�ֵ���캯���ɶ�ָ��ָ��Ķ���ִ�����
// ���ƣ������Ǳ�������ָ���ǳ���ơ�

#include <memory>

template<typename T>
// �������б������������Grid1ģ�������ָ�����͵���������
// ֻ��T��ָ�����͵�����²��ṩʵ�֡�
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

