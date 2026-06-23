class Solution {
public:
    static constexpr int MOD = 1000000007;

    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;

        vector<int> up(m), down(m);

        // Length = 2
        for (int v = 0; v < m; v++) {
            up[v] = v;            // smaller values before v
            down[v] = m - 1 - v; // larger values before v
        }

        for (int len = 3; len <= n; len++) {

            vector<int> prefUp(m), prefDown(m);

            prefUp[0] = up[0];
            prefDown[0] = down[0];

            for (int i = 1; i < m; i++) {
                prefUp[i] = (prefUp[i - 1] + up[i]) % MOD;
                prefDown[i] = (prefDown[i - 1] + down[i]) % MOD;
            }

            vector<int> newUp(m), newDown(m);

            int totalUp = prefUp[m - 1];

            for (int v = 0; v < m; v++) {

                // up[len][v]
                if (v > 0)
                    newUp[v] = prefDown[v - 1];

                // down[len][v]
                newDown[v] = (totalUp - prefUp[v] + MOD) % MOD;
            }

            up.swap(newUp);
            down.swap(newDown);
        }

        long long ans = 0;

        for (int v = 0; v < m; v++) {
            ans += up[v];
            ans += down[v];
            ans %= MOD;
        }

        return (int)ans;
    }
};