#include <iostream>
using namespace std;

//#define DP_TEST
//#define EXAM_TEST

#ifdef DP_TEST
    #include "dp.h"
#endif
#ifdef EXAM_TEST
    #include "exam.h"
#endif

int main()
{
    #ifdef DP_TEST
        DP::testrun();
    #endif
    #ifdef EXAM_TEST
        EXAM::testrun();
    #endif

    return 0;
}
