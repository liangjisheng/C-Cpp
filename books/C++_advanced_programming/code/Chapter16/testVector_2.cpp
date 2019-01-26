#include <iostream>
#include <vector>
#include <numeric>
#include <limits>
using namespace std;

int main()
{
    vector<double> doubleVector;
    // Initialize max to smallest number
    double Max = -numeric_limits<double>::infinity();
    for(size_t i = 1; true; i++){
        double temp;
        cout << "Enter score " << i << " (-1 to stop):";
        cin >> temp;
        if(-1 == temp)
            break;

        doubleVector.push_back(temp);
        if(temp > Max)
            Max = temp;
    }

    Max /= 100.0;
    cout << endl;
    // ����ȫ�ֵ� std::begin() std::end() ��ȡ������
    // Ҳ����ʹ�������ķ���
    for(vector<double>::iterator iter = begin(doubleVector);
        iter != end(doubleVector); ++iter){
            *iter /= Max;
            cout << *iter << " ";
    }
    cout << endl;

    return 0;
}
