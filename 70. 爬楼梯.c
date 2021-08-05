//主要思路：动态规划，状态转移方程：dp[i] = dp[i - 1] + dp[i - 2]
//注意细节：
//1、注意边界，(n == 0 || n == 1 || n == 2) return n
//2、遍历状态时，直接dp[0] = 1、dp[1] = 2，从n = 2开始

int climbStairs(int n){
    if (n == 0 || n == 1 || n == 2) return n;
    int dp[n];
    dp[0] = 1;
    dp[1] = 2;
    for (int i = 2; i < n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n - 1];
}