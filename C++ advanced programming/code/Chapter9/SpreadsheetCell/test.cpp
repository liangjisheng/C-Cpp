#include <iostream>
#include <vector>
#include "SpreadsheetCell.h"

using namespace std;

int main()
{
    vector<SpreadsheetCell*> cellArray(3);

    cellArray[0] = new StringSpreadsheetCell();
    cellArray[1] = new StringSpreadsheetCell();
    cellArray[2] = new DoubleSpreadsheetCell();

    cellArray[0]->set("hello");
    cellArray[1]->set("10");
    cellArray[2]->set("18");

    cout << cellArray[0]->getString() << endl;
    cout << cellArray[1]->getString() << endl;
    cout << cellArray[2]->getString() << endl;

    return 0;
}
