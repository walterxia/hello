#include "sort.h"

namespace SORT{ // From small to big (default)
    /* Step 1: first one is considered as sorted
       Step 2: pick up next one X, and compare with the sorted part (from back to forward)
       Step 3: if sorted compared element Z is bigger than X, move Z to next position
       Step 4: loop Step 3 until new Z is less that or equal to X
       Step 5: insert the X into the position
       Step 6: loop Step 2-5
    */
    void simpleInsertionSort(vector<int>& v) // Compare. In-place. O(n*n)
    {
        if(v.size() >= 2)
        {
            for(int i = 1; i < v.size(); ++i)
            {
                int tmp = v[i];
                for(int j = i-1; j >=0; ++j)
                {

                }
            }
        }
    }










    void testrun()
    {
        ENTER();
        vector<int> unsortedData{1,5,2,7,0,3,5,9,-1,-2};
    }
}
