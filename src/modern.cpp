#include "modern.h"

namespace MODERN{

    /*
        ����effective modern c++�н��ܣ�����������RVO�����ж�

        >>> return��ֵ������ ����ǩ���ķ���ֵ������ͬ
        >>> return����һ���ֲ�����
    */
    RValue temp_get() {
        RValue a;
        return a; //in general, the compiler do the Return value optimization����дΪRVO
    }

    /*
        ��ʱ���صĲ�����һ���ֲ����󣬶��Ǿֲ��������ֵ���á���������ʱ�޷�����rvo�Ż���
        ������ֻ�и���std::move(w)���ƶ�����һ����ʱ����Ȼ���ٽ�����ʱ����ֵ������Ŀ�ꡣ
        ���ԣ���Ҫ��ͼȥ����һ���ֲ��������ֵ���á�
    */
    RValue temp_get2() {
        RValue a;
        return move(a);
    }

    void testmove()
    {
        string str = "Hello";
        vector<string> v;
        //���ó���Ŀ������캯�����½��ַ����飬��������
        v.push_back(str);
        cout << "After copy, str is \"" << str << "\"\n";
        //�����ƶ����캯�����Ϳ�str���Ϳպ���ò�Ҫʹ��str
        v.push_back(move(str));
        cout << "After move, str is \"" << str << "\"\n";
        cout << "The contents of the vector are \"" << v[0] << "\", \"" << v[1] << "\"\n";

    }

    /*��ʱ����������RVO������������ʱ����ͬʱ��ʱ��������������ӳ�����rval_ref��ͬ���ȼ�������Ĵ���
    */
    std::vector<RValue> return_vector(void)
    {
        std::vector<RValue> tmp {RValue("1")};//,"2","3","4","5"};
        return tmp;
    }
    void return_vector_test()
    {
      //  std::vector<RValue> &&rval_ref = return_vector();
        //const std::vector<int>& rval_ref = return_vector(); // �ȼ����ϱ��ʽ��
      //  std::vector<RValue> rval_ref2 = return_vector();
    }

    std::vector<int>&& return_vector2(void)
    {
        std::vector<int> tmp {1,2,3,4,5};
        return std::move(tmp);
    }

    void return_vector_test2()
    {
        std::vector<int> &&rval_ref = return_vector2();
        //const std::vector<int>& rval_ref = return_vector(); // �ȼ����ϱ��ʽ��
    }

    void testrun()
    {
        //int& a = 5;  //cannot bind non-const lvalue reference of type 'int&' to an rvalue of type 'int'|
        const int& a = 5;
        int&& b = 6;
        //int&& c = b; //cannot bind rvalue reference of type 'int&&' to lvalue of type 'int'|
        int&& c1 = std::move(b);
        int c2 = b;

        //RValue r;
        //temp_get();
        //temp_get2();

        //testmove();
        return_vector_test();
        //return_vector_test2();

        (void)a;(void)b;(void)c1;(void)c2;//eliminate compiling warning
    }
}
