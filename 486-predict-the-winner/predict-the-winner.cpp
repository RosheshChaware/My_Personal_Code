class Solution {
public:
    int dp[21][21];

    int solve(vector<int>& nums, int l, int r) {
        if (l == r)
            return nums[l];

        if (dp[l][r] != -1)
            return dp[l][r];

        int takeLeft = nums[l] - solve(nums, l + 1, r);
        int takeRight = nums[r] - solve(nums, l, r - 1);

        return dp[l][r] = max(takeLeft, takeRight);
    }

    bool predictTheWinner(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return solve(nums, 0, nums.size() - 1) >= 0;
    }
};