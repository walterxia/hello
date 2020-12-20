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
        ENTER();
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
        ENTER();
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

    /* n iterate, select min/max in unsorted list and swap it with first one in unsorted list
       range shorten*/
    void selectionSort(vector<int>& v)
    {
        ENTER();
        int vSize = static_cast<int>(v.size());
        for(int i = 0; i < vSize; ++i)
        {
            int minIdx = i;
            for(int j = i+1; j < vSize; ++j)
            {
                if(v[j] < v[minIdx])
                    minIdx = j;
            }
            if(minIdx != i)
                swap(v[minIdx], v[i]);
        }
    }

    void shellSort(vector<int>& v) // gap, subsequence (can use different sort, such as bubble)
    {
        ENTER();
        int vSize = static_cast<int>(v.size());
        int gap = vSize;
        while(gap > 1)
        {
            gap = gap/2; // based on experience
            bool swapflag = false;
            for(int i = 0; i < vSize-1; ++i)
            {
                for(int j=0; j < vSize-i-gap; ++j)
                {
                    if(v[j]>v[j+gap])
                    {
                        swap(v[j], v[j+gap]);
                        swapflag = true;
                    }

                }
                if(!swapflag)
                    break;
            }
        }
    }

    void _quickSort(vector<int>& v, int s, int t, bool pivotByMiddle=false)
    {
        int low, high;
        if(s < t)
        {
            int pivot = s;
            if(pivotByMiddle)//head,tail,middle
            {
                int mid = (s+t)/2;
                int pivot = middle(v, s, mid, t);
                if(pivot != s)
                    swap(v[s], v[pivot]);
            }
            low = s;
            high = t+1;
            while(1)
            {
                do low++; //skip the pivot
                while(v[low]<=v[pivot] && low!= t);  // v[s] is the pivot. Also middle as pivot

                do high--;//skip invalid end
                while(v[high]>=v[pivot] && high!=s);

                if(low < high)
                    swap(v[low], v[high]);
                else
                    break;
            }
            swap(v[pivot], v[high]); //low==high
            _quickSort(v, s, high-1, pivotByMiddle); // skip v[high]
            _quickSort(v, high+1, t, pivotByMiddle);
        }
    }
    void quickSort(vector<int>& v) // partition, improved bubble. Swap. NOT Stable
    {
        ENTER();
        _quickSort(v, 0, v.size()-1);
    }
    void quickSort_pivot(vector<int>& v) // partition, improved bubble. Swap. NOT Stable
    {
        ENTER();
        _quickSort(v, 0, v.size()-1, true);
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

        vector<int> cc(unsortedData);
        selectionSort(cc);
        dump(cc);

        vector<int> dd(unsortedData);
        shellSort(dd);
        dump(dd);

        vector<int> ee(unsortedData);
        quickSort(ee);
        dump(ee);

        cout <<"*********************************************" <<endl;
        vector<int> tt = genRandomArray(20000000);

        auto x1 = tt;
        quickSort(x1);
        auto x2 = tt;
        quickSort_pivot(x2);
    }
}
