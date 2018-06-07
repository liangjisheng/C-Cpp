#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

//����ַ�����'S'��ͷ���򷵻�true
int MatchFirstChar( const string& str)
{
    string s("S") ;
    return s == str.substr(0,1) ;
}

//����count_if�㷨
void main()
{
    const int VECTOR_SIZE = 8 ;

    //���ɳ�Ա����Ϊstrings��vector������
    typedef vector<string > StringVector ;

    //�������������
    typedef StringVector::iterator StringVectorIt ;

    //����vector�����Ķ���
    StringVector NamesVect(VECTOR_SIZE) ;   

    //����������
    StringVectorIt start, end, it ;

    int result = 0 ;   // ���ͳ������

    //��ʼ��vector����NamesVect
    NamesVect[0] = "She" ;
    NamesVect[1] = "Sells" ;
    NamesVect[2] = "Sea" ;
    NamesVect[3] = "Shells" ;
    NamesVect[4] = "by" ;
    NamesVect[5] = "the" ;
    NamesVect[6] = "Sea" ;
    NamesVect[7] = "Shore" ;

    //������������ʼλ�ú���ֹλ��
    start = NamesVect.begin() ;   
    end = NamesVect.end() ; 

    //��ʾNamesVect������Ԫ��
    cout << "NamesVect: " ;
    for(it = start; it != end; it++)
        cout << *it << " " ;
    cout <<endl ;

    //ͳ�Ʋ���ʾNamesVect����������Ԫ������'S'�ַ���ͷ���ַ���
    result = count_if(start, end, MatchFirstChar) ;
    cout << "Number of elements that start with letter \"S\" = "
        << result << endl  ;

    //��ʾNamesVect����[1,6]֮���Ԫ��
    cout <<"NamesVect[1]--NamesVect[6]: " ;
    for(it =&NamesVect[1]; it != &NamesVect[7]; it++)
        cout << *it << " " ;
    cout <<endl ;

    //ͳ�Ʋ���ʾNamesVect����������Ԫ������'S'�ַ���ͷ���ַ���
    result = count_if(&NamesVect[1], &NamesVect[7], MatchFirstChar) ;
    cout << "Number of elements that start with letter \"S\" = "
        << result << endl  ;
}
