
// stream iterator 一种用来读写stream的迭代器，提供了必要
// 的抽象性，使得来自键盘的输入像是个群集(collection)，
// 从中能够读取内容，也可以把一个算法的输出结果重新导向到
// 某个文件或屏幕上

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>

using namespace std;

int main()
{
    vector<string> coll;
    /* read all words from standard input
    * - source: all strings until end-of-file (or error)
    * - destination: coll (inserting)
    */
    copy(istream_iterator<string>(cin),     // start of source
         istream_iterator<string>(),        // end of source
         back_inserter(coll));

    // print,before sort
    for(const auto& str : coll)
       cout<< str << ' ';
    cout << endl;

    // sort elements
    sort(coll.begin(),coll.end());

    // print,after sort
    for(const auto& str : coll)
       cout<< str << ' ';
    cout << endl;

    /* print all elements without duplicates
    * - source: coll
    * - destination: standard output (with newline between elements)
    */
    unique_copy(coll.begin(),coll.end(),        // source
                ostream_iterator<string>{cout,"\n"});      // destination

//    vector<int> coll1;
//    for(int i=1;i<=9;++i)
//        coll1.push_back(i);
//
//    // print
//    for(const auto& str : coll1)
//       cout<< str << ' ';
//    cout << endl;
//
//    // print1
//    vector<int>::iterator iter;
//    for(iter=coll1.begin();iter!=coll1.end();++iter)
//        cout << *iter << ' ';
//    cout << endl;
//
//    // print2
//    for(auto it= coll1.begin();it!=coll1.end();++it)
//        cout << *it << ' ';
//    cout << endl;

    return 0;
}
