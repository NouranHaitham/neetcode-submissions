class Solution {

private:
vector<int> dp = vector<int>(50,-1);


public:

    int climbStairsHelper(int n) {

        // base case
        if(n == 0) return 1;
        if(n < 0) return 0;

        if(dp[n] != -1) return dp[n];

        // transition
        return dp[n] = climbStairsHelper(n-1) + climbStairsHelper(n-2);
    }

    int climbStairs(int n) {
        return climbStairsHelper(n);
    }
};
