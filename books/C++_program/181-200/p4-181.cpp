#include <iostream>
#include <vector>

using namespace std;
typedef vector<int> INTVECTOR;

//����vector�����Ĺ���
void main(void)
{
    //vec1�����ʼΪ��
    INTVECTOR vec1;   
    //vec2���������10��ֵΪ6��Ԫ��  
    INTVECTOR vec2(10,6);  
    //vec3���������3��ֵΪ6��Ԫ��  
    INTVECTOR vec3(vec2.begin(),vec2.begin()+3);  

    //����һ����Ϊi��˫�������
    INTVECTOR::iterator i;

    //��ǰ�����ʾvec1�е�����
    cout<<"vec1.begin()--vec1.end():"<<endl;
    for (i =vec1.begin(); i !=vec1.end(); ++i)
        cout << *i << " ";
    cout << endl;

    //��ǰ�����ʾvec2�е�����
    cout<<"vec2.begin()--vec2.end():"<<endl;
    for (i =vec2.begin(); i !=vec2.end(); ++i)
        cout << *i << " ";
    cout << endl;

    //��ǰ�����ʾvec3�е�����
    cout<<"vec3.begin()--vec3.end():"<<endl;
    for (i =vec3.begin(); i !=vec3.end(); ++i)
        cout << *i << " ";
    cout << endl;
 
    //������ӺͲ����Ա����
    vec1.push_back(2);
    vec1.push_back(4);
    vec1.insert(vec1.begin()+1,5);
    vec1.insert(vec1.begin()+1,vec3.begin(),vec3.end());
    cout<<"push() and insert():" <<endl;
    for (i =vec1.begin(); i !=vec1.end(); ++i)
        cout << *i << " ";
    cout << endl;

    //���Ը�ֵ��Ա����
    vec2.assign(8,1);
    cout<<"vec2.assign(8,1):" <<endl;
    for (i =vec2.begin(); i !=vec2.end(); ++i)
        cout << *i << " ";
    cout << endl;

    //���������ຯ��
    cout<<"vec1.front()="<<vec1.front()<<endl;
    cout<<"vec1.back()="<<vec1.back()<<endl;
    cout<<"vec1.at(4)="<<vec1.at(4)<<endl;
    cout<<"vec1[4]="<<vec1[4]<<endl;

    //�����Ƴ���ɾ��
    vec1.pop_back();
    vec1.erase(vec1.begin()+1,vec1.end()-2);
    cout<<"vec1.pop_back() and vec1.erase():" <<endl;
    for (i =vec1.begin(); i !=vec1.end(); ++i)
        cout << *i << " ";
    cout << endl;

    //��ʾ���е�״̬��Ϣ
    cout<<"vec1.capacity(): "<<vec1.capacity()<<endl;
    cout<<"vec1.max_size(): "<<vec1.max_size()<<endl;
    cout<<"vec1.size(): "<<vec1.size()<<endl;
    cout<<"vec1.empty(): "<<vec1.empty()<<endl;

    //vector��������������
    cout<<"vec1==vec3: "<<(vec1==vec3)<<endl;
    cout<<"vec1<=vec3: "<<(vec1<=vec3)<<endl;
}
