int minimumTotal(int** triangle, int triangleSize, int* triangleColSize){
    int n = triangleSize;
    int dp[n];
    dp[0] = triangle[0][0];
    for (int i = 1; i < n; i++) {
        dp[i] = dp[i - 1] + triangle[i][i];
        for (int j = i - 1; j > 0; j--) {
            dp[j] = fmin(dp[j - 1], dp[j]) + triangle[i][j];
        }
        dp[0] += triangle[i][0];
    }
    int res = dp[0];
    for (int i = 1; i < n; i++) {
        res = fmin(res, dp[i]);
    }
    return res;
}