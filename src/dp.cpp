#include "dp.h"

namespace DP{

    namespace knapsack{
        /*
        vector<int>& weights: N kinds mapped weight
        vector<int>& values: N kinds mapped value
        W: total Weights
        N: total kinds
        */
        int knapsack01 (vector<int>& weights, vector<int>& values, int W, int N )
        {
            vector<vector<int>> dp(N+1, vector<int>(W+1, 0));    // dp[i][j] i: 前i个物品，j：不超过最大重量j
            for(int i = 1; i <= N; ++i)
            {
                int w = weights[i-1], v = values[i-1];
                for(int j = 1; j <= W; ++j)
                {
                    if(w <= j)
                    {
                        dp[i][j] = max(dp[i-1][j], dp[i-1][j-w] + v);
                    }
                    else
                    {
                        dp[i][j] = dp[i-1][j];
                    }
                }
            }
            return dp[N][W];
        }

        void knapsack01_testrun()
        {
            ENTER();
            vector<int> weights = {3, 2, 4};
            vector<int> values = {5, 4, 2};
            int W = 6, N = 3;
            cout << knapsack01(weights, values, W, N) << endl;
        }

        void run()
        {
            knapsack01_testrun();
        }
    }

    namespace FibonacciSequence{
        /* FibonacciSequence*/
        int fib_recursive(int n)
        {
            if(n <= 2)
                return 1;
            else
                return fib_recursive(n-1) + fib_recursive(n-2);
        }
        void recursiveRun()
        {
            ENTER();
            cout << fib_recursive(30) << endl;
        }

        int fib_memo_helper(vector<int>& memo, int n) // from top to down
        {
            if(memo[n] != 0)
                return memo[n];
            else
                memo[n] = fib_memo_helper(memo, n-1) + fib_memo_helper(memo, n-2);
            return memo[n];
        }
        int fib_memo(int n)
        {
            if(n <= 2)
                return 1;
            else
            {
                vector<int> memo(n+1, 0);
                memo[1] = memo[2] = 1;
                return fib_memo_helper(memo, n);
            }
        }
        void memoRun()
        {
            ENTER();
            cout << fib_memo(30) << endl;
        }

        int fib_dp(int n)
        {
            if(n==1 || n==2)
                return 1;
            vector<int> dp(n+1, 0);
            dp[2] = dp[1] = 1; //base case
            for(int i = 3; i <=n; ++i)
                dp[i] = dp[i-1] + dp[i-2];
            return dp[n];
        }
        void dpRun()
        {
            ENTER();
            cout << fib_dp(30) << endl;
        }

        int fib_dpStateCompress(int n)
        {
            if(n==1 || n==2)
                return 1;
            int prev, curr;
            prev = curr = 1;
            for(int i = 3; i <=n; ++i)
            {
                int sum = prev + curr;
                prev = curr;
                curr = sum;
            }
            return curr;
        }
        void dpStateCompressRun()
        {
            ENTER();
            cout << fib_dpStateCompress(30) << endl;
        }
        void run()
        {
            recursiveRun();
            memoRun();
            dpRun();
            dpStateCompressRun();
        }
    }
    namespace coinChange{ // 最小零钱数
        int recursive(vector<int>& coins, int target) //from top to down
        {
            if(target < 0) return -1;
            else if(target == 0) return 0;
            else
            {
                int res = numeric_limits<int>::max();
                for(auto& coin : coins)
                {
                    if(target - coin < 0)
                        continue;
                    else
                        res = min(recursive(coins, target - coin)+1, res);
                }
                return res == numeric_limits<int>::max() ? -1 : res;
            }
        }

        void coinChangeRecursiveRun()
        {
            ENTER();
            vector<int> coins = {1,2,5};
            int target = 30;
            cout << recursive(coins, target) << endl;
        }

        int recursive_pruneByMemoHelper(vector<int>& memo, vector<int>& coins, int target)
        {
            if(memo[target] != numeric_limits<int>::max())
                return memo[target];
            else
            {
                int res = numeric_limits<int>::max();
                for(auto& coin : coins)
                {
                    if(target - coin < 0)
                        continue;
                    else
                        res = min(recursive_pruneByMemoHelper(memo, coins, target - coin)+1, res);
                }
                memo[target] = res;
                return memo[target];
            }
        }
        int recursive_pruneByMemo(vector<int>& coins, int target) //from top to down
        {
            vector<int> memo(target+1, numeric_limits<int>::max());
            memo[0] = 0; // base case!
            int res = recursive_pruneByMemoHelper(memo, coins, target);
            return res == numeric_limits<int>::max() ? -1 : res;
        }

        void coinChangeRecursivePruneByMemoRun()
        {
            ENTER();
            vector<int> coins = {1,2,5};
            int target = 30;
            cout << recursive_pruneByMemo(coins, target) << endl;
        }

        int dp(vector<int>& coins, int target) // from down to up
        {
            // State:对应总钱数的最小零钱数
            vector<int> dp(target+1, target+1); // target+1硬币数量超全部是1元的
            // base state
            dp[0] = 0;
            for(int i = 1; i <= target; ++i)
            {
                for(auto& coin: coins)
                {
                    if(i - coin < 0) continue;
                    else dp[i] = min(dp[i], dp[i - coin] + 1);
                }
            }
            //for
            return dp[target] == target+1 ? -1 : dp[target];
        }
        void coinChangeDpRun()
        {
            ENTER();
            vector<int> coins = {1,2,5};
            int target = 30;
            cout << dp(coins, target) << endl;
        }
        void run()
        {
            coinChangeRecursiveRun();
            coinChangeRecursivePruneByMemoRun();
            coinChangeDpRun();
        }
    }

    void testrun()
    {
        knapsack::run();
        FibonacciSequence::run();
        coinChange::run();
    }
}
