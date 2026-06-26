class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int bestend=nums[0];
        int ans = nums[0];

        for(int i=1;i<nums.size();i++){
            int s1=nums[i];
            int s2=bestend+nums[i];

            bestend=max(s2,s1);
            ans=max(ans,bestend);
        }
        return ans;
    }
};