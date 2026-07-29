class Solution {
public:
    long long countWays(vector<int>& freq, int total, int k) {
        long long ways = 1;
        int used = 0;

        for (int i = 0; i < 26; i++) {
            int cnt = freq[i];
            if (cnt == 0) continue;
            for (int j = 1; j <= cnt; j++) {
                ways = ways * (used + j) / j;
                if (ways >= k) {
                    return k;
                }
            }
            used += cnt;
        }
        return ways;
    }
    string smallestPalindrome(string s, int k) {
        vector<int> freq(26, 0);
        for (char ch : s) {
            freq[ch - 'a']++;
        }
        vector<int> halfFreq(26);
        string middle = "";
        for (int i = 0; i < 26; i++) {
            halfFreq[i] = freq[i] / 2;
            if (freq[i] % 2) {
                middle += char('a' + i);
            }
        }

        int halfLength = s.size() / 2;
        if (countWays(halfFreq, halfLength, k) < k) {
            return "";
        }
        string left = "";
        for (int pos = 0; pos < halfLength; pos++) {
            for (int ch = 0; ch < 26; ch++) {
                if (halfFreq[ch] == 0) {
                    continue;
                }
                halfFreq[ch]--;
                long long ways = countWays(
                    halfFreq,
                    halfLength - pos - 1,
                    k
                );
                if (ways >= k) {
                    left += char('a' + ch);
                    break;
                }
                k -= ways;
                halfFreq[ch]++;
            }
        }
        string right = left;
        reverse(right.begin(), right.end());
        return left + middle + right;
    }
};