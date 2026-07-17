class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {

        int mx = *max_element(nums.begin(), nums.end());

        vector<long long> freq(mx + 1, 0);

        for (int x : nums)
            freq[x]++;

        vector<long long> cnt(mx + 1, 0);

        for (int d = 1; d <= mx; d++)
        {
            for (int multiple = d; multiple <= mx; multiple += d)
            {
                cnt[d] += freq[multiple];
            }
        }

        vector<long long> exact(mx + 1, 0);

        for (int d = mx; d >= 1; d--)
        {
            exact[d] = cnt[d] * (cnt[d] - 1) / 2;

            for (int multiple = 2 * d; multiple <= mx; multiple += d)
            {
                exact[d] -= exact[multiple];
            }
        }

        vector<long long> pref(mx + 1, 0);

        for (int d = 1; d <= mx; d++)
        {
            pref[d] = pref[d - 1] + exact[d];
        }

        vector<int> ans;

        for (long long q : queries)
        {
            int low = 1;
            int high = mx;

            while (low < high)
            {
                int mid = low + (high - low) / 2;

                if (pref[mid] > q)
                    high = mid;
                else
                    low = mid + 1;
            }

            ans.push_back(low);
        }

        return ans;
    }
};