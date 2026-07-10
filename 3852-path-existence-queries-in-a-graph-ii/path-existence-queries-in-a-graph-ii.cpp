class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {

        vector<pair<int,int>> arr;

        for(int i=0;i<n;i++){
            arr.push_back({nums[i],i});
        }

        sort(arr.begin(),arr.end());

        int lg=20;
        vector<vector<int>> jump(n,vector<int>(lg));

        int j=n-1;

        for(int i=n-1;i>=0;i--){

            while(arr[j].first-arr[i].first>maxDiff){
                j--;
            }

            int x=arr[i].second;
            int y=arr[j].second;

            jump[x][0]=y;

            for(int k=1;k<lg;k++){
                jump[x][k]=jump[jump[x][k-1]][k-1];
            }
        }

        vector<int> ans;

        for(auto it:queries){

            int a=it[0];
            int b=it[1];

            if(nums[a]>nums[b]){
                swap(a,b);
            }

            if(a==b){
                ans.push_back(0);
                continue;
            }

            if(nums[a]==nums[b]){
                ans.push_back(1);
                continue;
            }

            int cnt=0;

            for(int k=lg-1;k>=0;k--){

                if(nums[jump[a][k]]<nums[b]){
                    cnt+=(1<<k);
                    a=jump[a][k];
                }
            }

            if(nums[jump[a][0]]<nums[b]){
                ans.push_back(-1);
            }
            else{
                ans.push_back(cnt+1);
            }
        }

        return ans;
    }
};