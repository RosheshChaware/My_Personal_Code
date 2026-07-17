class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int high=0,low=0;
        int res= INT_MIN;
        unordered_map<int,int>mpp;
        for(high=0;high<nums.size();high++){
            mpp[nums[high]]++;

            while(mpp[0]>k){
                mpp[nums[low]]--;
                low++;

            }
            int len=high-low+1;
                 res = max(res,len);
        }
        return res;
    }
};