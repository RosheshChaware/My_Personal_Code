class Solution {
public:
    const int MOD = 1e9 + 7;

    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {

        vector<int> pos, d;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] != '0') {
                pos.push_back(i);
                d.push_back(s[i] - '0');
            }
        }

        int n = d.size();

        if (n == 0)
            return vector<int>(queries.size(), 0);

        vector<long long> preNum(n), preSum(n), p10(n + 1);

        p10[0] = 1;
        for (int i = 1; i <= n; i++)
            p10[i] = (p10[i - 1] * 10) % MOD;

        preNum[0] = d[0];
        preSum[0] = d[0];

        for (int i = 1; i < n; i++) {
            preNum[i] = (preNum[i - 1] * 10 + d[i]) % MOD;
            preSum[i] = preSum[i - 1] + d[i];
        }

        vector<int> ans;

        for (auto &q : queries) {

            int l = q[0], r = q[1];

            int L = lower_bound(pos.begin(), pos.end(), l) - pos.begin();
            int R = upper_bound(pos.begin(), pos.end(), r) - pos.begin() - 1;

            if (L > R) {
                ans.push_back(0);
                continue;
            }

            long long sum = preSum[R];
            if (L > 0)
                sum -= preSum[L - 1];

            long long num = preNum[R];
            if (L > 0)
                num = (num - preNum[L - 1] * p10[R - L + 1] % MOD + MOD) % MOD;

            ans.push_back((num * sum) % MOD);
        }

        return ans;
    }
};