#include <iostream>
using namespace std;

//#define DP_TEST
//#define EXAM_TEST
//#define MODERN_TEST
#define SORT_TEST

#ifdef DP_TEST
    #include "dp.h"
#endif
#ifdef EXAM_TEST
    #include "exam.h"
#endif
#ifdef MODERN_TEST
    #include "modern.h"
#endif
#ifdef SORT_TEST
    #include "sort.h"
#endif

int main()
{
    #ifdef DP_TEST
        DP::testrun();
    #endif
    #ifdef EXAM_TEST
        EXAM::testrun();
    #endif
    #ifdef MODERN_TEST
        MODERN::testrun();
    #endif
    #ifdef SORT_TEST
        SORT::testrun();
    #endif

    return 0;
}
