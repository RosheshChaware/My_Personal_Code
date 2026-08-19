class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& a) {
        unordered_map<int, int> mp;
        for(auto x : a)
            mp[x[0]] |= (1 << x[1]);
        int ans = (n - mp.size()) * 2;
        for(auto [r, mask] : mp) {
            bool l = !(mask & 60);    
            bool m = !(mask & 240);   
            bool rr = !(mask & 960);  

            if(l && rr) ans += 2;
            else if(l || m || rr) ans++;
        }

        return ans;
    }
};