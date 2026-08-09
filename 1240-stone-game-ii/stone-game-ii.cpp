class Solution {
public:
    int n;
    vector<int> suffix;
    int dp[101][102];

    int solve(int i, int M) {
        if (i>=n)
            return 0;
        if (2* M >= n - i)
            return suffix[i];

        if (dp[i][M] != -1)
            return dp[i][M];
        int ans = 0;
        for (int X = 1; X <= 2 * M && i + X <= n; X++) {
            int taken = suffix[i]-suffix[i + X];
            int opponent = solve(i+X, max(M, X));
            ans = max(ans, taken+suffix[i + X] - opponent);
        }
        return dp[i][M] = ans;
    }
    int stoneGameII(vector<int>& piles) {
        n = piles.size();


        suffix.resize(n + 1, 0);
        for (int i = n - 1; i >= 0; i--) {
            suffix[i] = suffix[i + 1] + piles[i];
        }
        memset(dp, -1, sizeof(dp));
        return solve(0, 1);
    }
};