class Solution {
public:
    int mod = 1e9 + 7;
    int dp[201][201][201];

    int fun(int i, int g1, int g2, vector<int>& nums)
    {
        if(i == nums.size())
        {
            if(g1 == g2 && g1 != 0)
                return 1;
            return 0;
        }
        if(dp[i][g1][g2] != -1)
            return dp[i][g1][g2];

        long long ans = 0;
        ans += fun(i + 1, __gcd(g1, nums[i]), g2, nums);
        ans += fun(i + 1, g1, __gcd(g2, nums[i]), nums);
        ans += fun(i + 1, g1, g2, nums);
        return dp[i][g1][g2] = ans % mod;
    }

    int subsequencePairCount(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return fun(0, 0, 0, nums);
    }
};