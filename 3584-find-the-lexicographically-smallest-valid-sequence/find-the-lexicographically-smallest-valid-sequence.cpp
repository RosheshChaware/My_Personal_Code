class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        vector<int> ans(m);

        // last[j] = position in word1 where word2[j]
        // can be matched in the suffix.
        vector<int> last(m, -1);

        int i = n - 1;
        int j = m - 1;

        while (i >= 0 && j >= 0) {
            if (word1[i] == word2[j]) {
                last[j] = i;
                j--;
            }
            i--;
        }
        bool canSkip = true;
        j = 0;
        for (i =0; i< n && j <m; i++) {
            if (word1[i]==word2[j]) {
                ans[j] = i;
                j++;
            }
            else if (canSkip &&
                     (j == m - 1|| i < last[j + 1])) {

                ans[j] = i;
                j++;
                canSkip = false;
            }
        }

        if (j == m)
            return ans;

        return {};
    }
};