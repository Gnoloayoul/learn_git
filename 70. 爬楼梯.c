//��Ҫ˼·����̬�滮��״̬ת�Ʒ��̣�dp[i] = dp[i - 1] + dp[i - 2]
//ע��ϸ�ڣ�
//1��ע��߽磬(n == 0 || n == 1 || n == 2) return n
//2������״̬ʱ��ֱ��dp[0] = 1��dp[1] = 2����n = 2��ʼ

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