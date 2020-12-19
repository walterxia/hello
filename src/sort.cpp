#include "sort.h"

namespace SORT{ // From small to big (default)

    void dump(vector<int>& v )
    {
        for(auto& i: v)
            cout << i << " ";
        cout <<endl;
    }


    /* Step 1: first one is considered as sorted
       Step 2: pick up next one X, and compare with the sorted part (from back to forward)
       Step 3: if sorted compared element Z is bigger than X, move Z to next position
       Step 4: loop Step 3 until new Z is less that or equal to X
       Step 5: insert the X into the position
       Step 6: loop Step 2-5
    */
    void simpleInsertionSort(vector<int>& v) // Compare. In-place. O(n*n)
    {
        int vSize = static_cast<int>(v.size());
        if(vSize >= 2)
        {
            for(int i = 1; i < vSize; ++i)
            {
                int tmp = v[i];
                int j = i-1;
                while(j >=0 && tmp < v[j])
                {
                    v[j+1] = v[j];
                    j--;  // ERROR: if above one: v[j+1] = v[j--] warning: operation on 'j' may be undefined [-Wsequence-point]
                }
                v[j+1] = tmp; //ERROR: v[0] cannot get if i, j is unsigned~~
            }
        }
    }

    /*iterate first to last one and compare to neigbour. bigger, then swap
    the range shorten
    sorted part is put in last
    */
    void bubbleSort(vector<int>& v)
    {
        int vSize = static_cast<int>(v.size());
        for(int i = 0; i < vSize-1; ++i)
        {
            bool swapflag = false;
            for(int j=0; j < vSize-i-1; ++j) //ERROR: -1 must add
            {
                if(v[j]>v[j+1])
                {
                    swap(v[j], v[j+1]);
                    swapflag = true;
                }

            }
            if(!swapflag) // Optimization:
                break;
        }
    }

    void selectionSort(vector<int>& v)
    {

    }


    void testrun()
    {
        ENTER();
        vector<int> unsortedData{1,5,2,7,0,3,5,9,-1,-2};
        dump(unsortedData);

        vector<int> aa(unsortedData);
        simpleInsertionSort(aa);
        dump(aa);

        vector<int> bb(unsortedData);
        bubbleSort(bb);
        dump(bb);

    }
}
