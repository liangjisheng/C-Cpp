#ifndef SPREADSHEETCELL_H_INCLUDED
#define SPREADSHEETCELL_H_INCLUDED

// 纯虚函数作为抽象类，不能创建对象实例，
// SpreadsheetCell cell;        // Error! Attempts createing abstract class instance
// SpreadsheetCell* ptr = nullptr;      // ok!
// 抽象类提供了一种禁止其他代码直接实例化对象的方法，而它的子类可以实例化对象

class SpreadsheetCell {
public:
    SpreadsheetCell();
    virtual ~SpreadsheetCell();
    virtual void set (const std::string& inString) = 0;
    virtual std::string getString() const = 0;
};


class DoubleSpreadsheetCell;
// 子类的单元格不应该是抽象的，应当实现从父类继承的所有纯虚方法
// 如果没有实现的话，则子类也是抽象，不能实例化对象

// 为了提供将DoubleSpreadsheetCell转换为StringSpreadsheetcell的功能
// 应该添加一个类型转换构造函数，这个构造函数类似于复制构造函数，
// 但参数不是同类对象的引用，而是同级类对象的引用
// 类型转换构造函数和类型转换不同，类型转换无法将一个对象转换同级类的另一个对象

class StringSpreadsheetCell : public SpreadsheetCell{
public:
    StringSpreadsheetCell();
    StringSpreadsheetCell(const DoubleSpreadsheetCell& inDoubleCell);
    virtual void set(const std::string& inString) override;
    virtual std::string getString() const override;
private:
    std::string mValue;
};


class DoubleSpreadsheetCell : public SpreadsheetCell {
public:
    DoubleSpreadsheetCell();
    virtual void set(double inDouble);
    virtual void set(const std::string& inString);
    virtual std::string getString() const override;
private:
    static std::string DoubleToString(double inValue);
    static double StringToDouble(const std::string& inValue);
    double mValue;
};

#endif // SPREADSHEETCELL_H_INCLUDED
