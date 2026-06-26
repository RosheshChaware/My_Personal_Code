class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        
        vector<long long> prefix(n + 1, 0);
        
       
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + (nums[i] == target ? 1 : -1);
        }

       
        vector<long long> sorted = prefix;
        sort(sorted.begin(), sorted.end());
        sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());

        auto getIndex = [&](long long x) {
            return lower_bound(sorted.begin(), sorted.end(), x) - sorted.begin() + 1;
        };

        int m = sorted.size();
        vector<long long> bit(m + 2, 0);

        auto update = [&](int i) {
            while (i <= m) {
                bit[i]++;
                i += i & -i;
            }
        };

        auto query = [&](int i) {
            long long sum = 0;
            while (i > 0) {
                sum += bit[i];
                i -= i & -i;
            }
            return sum;
        };

        long long ans = 0;

        
        update(getIndex(0));

        for (int j = 1; j <= n; j++) {
            int idx = getIndex(prefix[j]);

            
            ans += query(idx - 1);

            update(idx);
        }

        return ans;
    }
};