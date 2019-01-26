
// C++��׼������еı�ʶ����������namespace std��
// #include<iostream>
// �Ӳ���ϵͳ�ĽǶȿ�����ͷ�ļ�������ʽ������ζ�ű�עͷ�ļ�
// û����չ������δ����ɱ�����������C++ϵͳ�����Զ����һ��
// ��չ��.�Լ�д��ͷ�ļ���ü���.h�����ֱ�׼ͷ�ļ�

// ��׼�쳣��(standard exception classes),���Ա�����׼�����
// �׳��������쳣���������Ի���exception����������������׼�쳣
// ��Ļ��࣬��׼�쳣���λ3��
// 1:���Ա���֧�ֵ��쳣
// 2:C++��׼������׳����쳣
// 3:����������(scope of a program)֮�ⷢ�����쳣

// 1:���Ա���֧�ֵ��쳣
// newʧ�ܺ��׳�bad_alloc�쳣
// dynamic_castʧ��ʱ�׳�bad_cast�쳣
// RTTI�����У��������typeid()�Ĳ���Ϊ0���ָ��ʱ�׳�bad_typeid�쳣
// ������Ԥ�ڵ��쳣�׳�bad_exception,bad_exception����unexpected()

// 2:C++��׼������׳����쳣
// C++��׼���쳣������logic_error
// invalid_argument,length_error,out_of_range
// domain_error(רҵ���򷶳��ڵĴ���)
// ��׼IO�ṩ��һ��ios_base::failure�������쳣����������(data stream)
// ���ڴ�������ڵ����ļ�β�˶�����״̬�ı�ʱ���Ϳ����׳��쳣

// 3:����������(scope of a program)֮�ⷢ�����쳣
// range_error,overflow_error,underflow_error

#include<exception>			// for exception bad_exception
#include<new>	// for bad_alloc
#include<typeinfo>	// for bad_cast bad_typeid
#include<stdexcept>	// �����쳣
#include<ios>		// for ios_base::failure

// C++��׼����������ط�������������������ڴ����ú�Ѱַ������
// �Ķ����Ϊ������(allocator).���������ֳ�һ���ض����ڴ�ģ��(memory model)
// ������ö����ͬ�����������󣬱������ͬһ�������в��ò�ͬ���ڴ�ģ��