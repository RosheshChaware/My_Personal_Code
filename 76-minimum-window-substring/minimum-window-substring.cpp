class Solution {
public:
    string minWindow(string s, string t) {

        vector<int> freq(256, 0);
        for(char ch : t)
        {
            freq[ch]++;
        }

        int low = 0, high = 0;
        int count = t.size();

        int minLen = INT_MAX;
        int start = 0;
        for(high = 0; high < s.size(); high++)
        {
            if(freq[s[high]] > 0)
                count--;
            freq[s[high]]--;
            while(count == 0)
            {
                int len = high - low + 1;
                if(len < minLen)
                {
                    minLen = len;
                    start = low;
                }
                freq[s[low]]++;
                if(freq[s[low]] > 0)
                    count++;
                low++;
            }
        }
        if(minLen == INT_MAX)
            return "";
        return s.substr(start, minLen);
    }
};