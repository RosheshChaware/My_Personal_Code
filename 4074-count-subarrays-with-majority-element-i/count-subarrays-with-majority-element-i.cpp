class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();

        vector<int> pref(n + 1, 0);

        for (int i = 0; i < n; i++) {
            pref[i + 1] = pref[i] + (nums[i] == target ? 1 : -1);
        }

        long long ans = 0;

        for (int j = 1; j <= n; j++) {
            for (int i = 0; i < j; i++) {
                if (pref[j] > pref[i]) {
                    ans++;
                }
            }
        }

        return (int)ans;
    }
};