#include <iostream>
#include <vector>
#include <set>
using namespace std;
namespace EXAM{
    namespace FamaWeighAllWeights{
    // performance is better than STL Swap http://www.cplusplus.com/reference/algorithm/swap/
    #define SWAP_BY_XOR(a, b) {a=a^b;b=a^b;a=a^b;}

        bool isOK(vector<int>& fmWeights)
        {
            int min, max;
            max = min = *fmWeights.cbegin();
            for(auto& fw: fmWeights)
            {
                max = fw;
                if(min > max)
                    SWAP_BY_XOR(min, max);
                while(0 != max%min)  // 辗转相除法一般指欧几里得算法求最大公约数
                {
                    max = max%min;
                    //if(min > max)  // Can cancel this judgement as max < min after % operation
                    SWAP_BY_XOR(min, max);
                } // min save the Greatest Common Division
                if(min == 1)
                    return true;
            }
            return false;
        }

        void run()
        {
            int fmKind;
            cin >> fmKind;
            vector<int> fmWeights;
            int fw;
            for(int i = 0; i < fmKind; ++i)
            {
                cin >> fw;
                fmWeights.push_back(fw);
            }
            cout << (isOK(fmWeights) ? "YES" : "NO") << endl;
        }
    }

    void testrun()
    {
        FamaWeighAllWeights::run();
    }
}
