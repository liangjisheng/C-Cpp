
#include <iostream>
#include <limits>
#include <sstream>
#include "SpreadsheetCell.h"

using namespace std;

SpreadsheetCell::SpreadsheetCell() { }

SpreadsheetCell::~SpreadsheetCell() { }


// #NOVALUE说明这个值尚未设置
StringSpreadsheetCell::StringSpreadsheetCell() : mValue("#NOVALUE") {}

void StringSpreadsheetCell::set(const string& inString){
    mValue = inString;
}

string StringSpreadsheetCell::getString() const {
    return mValue;
}


DoubleSpreadsheetCell::DoubleSpreadsheetCell()
: mValue(std::numeric_limits<double>::quiet_NaN())
{
    // NaN表示不是一个数字
}

void DoubleSpreadsheetCell::set(double inDouble)
{
    mValue = inDouble;
}

void DoubleSpreadsheetCell::set(const string& inString) {
    mValue = StringToDouble(inString);
}

string DoubleSpreadsheetCell::getString() const{
    return DoubleToString(mValue);
}

string DoubleSpreadsheetCell::DoubleToString(double inValue){
    ostringstream ostr;
    ostr << inValue;
    return ostr.str();
}

double DoubleSpreadsheetCell::StringToDouble(const string& inValue) {
    double temp;
    istringstream istr(inValue);
    istr >> temp;
    if(istr.fail() || !istr.eof())
        return 0;

    return temp;
}

