class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {

        vector<vector<pair<int,int>>> adj(n + 1);

        for(auto &it : roads){
            int u = it[0];
            int v = it[1];
            int w = it[2];

            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }

        vector<int> vis(n + 1,0);
        int ans = INT_MAX;

        queue<int> q;
        q.push(1);
        vis[1] = 1;

        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(auto &[nbr,wt] : adj[node]){
                ans = min(ans, wt);

                if(!vis[nbr]){
                    vis[nbr] = 1;
                    q.push(nbr);
                }
            }
        }

        return ans;
    }
};