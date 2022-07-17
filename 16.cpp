// https://leetcode.com/problems/out-of-boundary-paths/
class Solution {
public:
    int dp[55][55][55];
    int mod = 1000000007;
    int func(int m, int n, int S, int i, int j){
        if(i < 0 || i >= m || j < 0 || j >= n) return 1;
        if(S <= 0) return 0;
        if(dp[i][j][S] != -1) return dp[i][j][S];
        long long x = 0;
        x += func(m, n, S - 1, i-1, j);
        x += func(m, n, S - 1, i + 1, j);
        x += func(m, n, S - 1, i, j + 1);
        x += func(m, n, S - 1, i, j - 1);
        x %= 1000000007;
        dp[i][j][S] = x;
        return dp[i][j][S];
    }
    int findPaths(int m, int n, int S, int i, int j) {
        memset(dp, -1, sizeof(dp));
        return func(m, n, S, i, j);
    }
};