#include "modern.h"

namespace MODERN{
    RValue temp_get() {
        RValue a;
        return a;
    }

    void testrun()
    {
        //int& a = 5;  //cannot bind non-const lvalue reference of type 'int&' to an rvalue of type 'int'|
        const int& a = 5;
        int&& b = 6;
        //int&& c = b; //cannot bind rvalue reference of type 'int&&' to lvalue of type 'int'|
        int&& c1 = std::move(b);
        int c2 = b;

        RValue r;
        temp_get();

        (void)a;(void)b;(void)c1;(void)c2;//eliminate compiling warning
    }
}
