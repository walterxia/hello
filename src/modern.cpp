#include "modern.h"

namespace MODERN{

    /*
        根据effective modern c++中介绍，编译器进行RVO条件有二

        >>> return的值类型与 函数签名的返回值类型相同
        >>> return的是一个局部对象
    */
    RValue temp_get() {
        RValue a;
        return a; //in general, the compiler do the Return value optimization，缩写为RVO
    }

    /*
        此时返回的并不是一个局部对象，而是局部对象的右值引用。编译器此时无法进行rvo优化，
        能做的只有根据std::move(w)来移动构造一个临时对象，然后再将该临时对象赋值到最后的目标。
        所以，不要试图去返回一个局部对象的右值引用。
    */
    RValue temp_get2() {
        RValue a;
        return move(a);
    }

    void testmove()
    {
        string str = "Hello";
        vector<string> v;
        //调用常规的拷贝构造函数，新建字符数组，拷贝数据
        v.push_back(str);
        cout << "After copy, str is \"" << str << "\"\n";
        //调用移动构造函数，掏空str，掏空后，最好不要使用str
        v.push_back(move(str));
        cout << "After move, str is \"" << str << "\"\n";
        cout << "The contents of the vector are \"" << v[0] << "\", \"" << v[1] << "\"\n";

    }

    /*此时，并不调用RVO，拷贝构造临时对象，同时临时对象的生命周期延长至与rval_ref相同，等价于下面的代码
    */
    std::vector<RValue> return_vector(void)
    {
        std::vector<RValue> tmp {RValue("1")};//,"2","3","4","5"};
        return tmp;
    }
    void return_vector_test()
    {
      //  std::vector<RValue> &&rval_ref = return_vector();
        //const std::vector<int>& rval_ref = return_vector(); // 等价于上表达式子
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
        //const std::vector<int>& rval_ref = return_vector(); // 等价于上表达式子
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
