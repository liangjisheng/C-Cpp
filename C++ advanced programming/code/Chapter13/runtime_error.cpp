#include <iostream>
#include <stdexcept>        // for invalid_argument and runtime_error
#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>
using namespace std;

void readIntegerFile(const string& fileName,vector<int>& dest)
{
    ifstream istr;
    int temp;
    istr.open(fileName.c_str());
    if(istr.fail()){
        // We failed to open the file: throw an exception
        throw invalid_argument("Unable to open the file.");
    }

    // Read the integer one by one and add them to the vector
    while(istr >> temp) {       // �����������ã������ж������Ƿ�ɹ�
        dest.push_back(temp);
    }

    if(istr.eof()) {
        // reach the end-of-file,throw an exception
        throw runtime_error("Error reading the file.");
    }
}
// invalid_argument �� runtime_error û�й���Ĭ�Ϲ��캯����ֻ����
// �ַ����������Ĺ��캯����

// �������δ������쳣��������ڽ��� terminate() �����������������
// <cstdlib>�е�abort()����ֹ���򣬿ɵ���set_terminate()���������Լ�
// ��terminate_handler,�����������ָ��ص�����(��û�в�����Ҳû�з���ֵ)
// ��ָ����������
// #include <exception>     // for terminate(),set_terminate(),terminate_handler

void myTerminate(){
    cout << "Uncaught exception" << endl;
    exit(1);
}

int main()
{
    string fileName = "test.txt";
    vector<int> dest;
    set_terminate(myTerminate);     // ���ؾɵ� terminate_handle

    try{
        readIntegerFile(fileName.c_str(),dest);
    }catch(const invalid_argument& e) {
        cerr << e.what() << endl;
    }catch (const runtime_error& e) {
        cerr << e.what() << endl;
        return 1;
    }catch (...) {
        // Handle all other exception
    }

    return 0;
}
