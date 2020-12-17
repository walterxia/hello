#include "common.h"

struct RValue
{
    RValue():_name("default"){cout << "default ctor" << endl;}
    RValue(string name):_name(name){cout << name << " ctor" << endl;}
    ~RValue(){cout << "~dctor" << endl;}
    RValue(const RValue& other)
    {
        cout << "const RValue& ctor" << endl;
    }

    RValue(RValue&& other)
    {
        cout << "RValue&& ctor"  << endl;
    }

    string _name;
};


namespace MODERN{
    void testrun();
}
