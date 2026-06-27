class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long, int> freq;

        for (int x : nums)
            freq[x]++;

        int ans = 1;

         if (freq.count(1)) {
            ans = max(ans, (freq[1] % 2 == 0) ? freq[1] - 1 : freq[1]);
        }

        for (auto &[num, cnt] : freq) {
            if (num == 1) continue;

            long long cur = num;
            int len = 0;

            while (freq[cur] >= 2) {
                if (cur > 1000000000LL / cur) break;

                long long nxt = cur * cur;

                 if (!freq.count(nxt)) break;

                len += 2;
                cur = nxt;
            }

            if (freq[cur] >= 1)
                len++;
            else if (len > 0)
                len--;

            ans = max(ans, len);
        }

        return ans;
    }
};