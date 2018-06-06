#ifndef SPREADSHEETCELL_H_INCLUDED
#define SPREADSHEETCELL_H_INCLUDED

// ���麯����Ϊ�����࣬���ܴ�������ʵ����
// SpreadsheetCell cell;        // Error! Attempts createing abstract class instance
// SpreadsheetCell* ptr = nullptr;      // ok!
// �������ṩ��һ�ֽ�ֹ��������ֱ��ʵ��������ķ������������������ʵ��������

class SpreadsheetCell {
public:
    SpreadsheetCell();
    virtual ~SpreadsheetCell();
    virtual void set (const std::string& inString) = 0;
    virtual std::string getString() const = 0;
};


class DoubleSpreadsheetCell;
// ����ĵ�Ԫ��Ӧ���ǳ���ģ�Ӧ��ʵ�ִӸ���̳е����д��鷽��
// ���û��ʵ�ֵĻ���������Ҳ�ǳ��󣬲���ʵ��������

// Ϊ���ṩ��DoubleSpreadsheetCellת��ΪStringSpreadsheetcell�Ĺ���
// Ӧ�����һ������ת�����캯����������캯�������ڸ��ƹ��캯����
// ����������ͬ���������ã�����ͬ������������
// ����ת�����캯��������ת����ͬ������ת���޷���һ������ת��ͬ�������һ������

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
