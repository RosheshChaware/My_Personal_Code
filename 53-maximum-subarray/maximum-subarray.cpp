class Solution {
public:
    int maxSubArray(vector<int>& nums) {
      int sum=nums[0];
      int last=nums[0];
      
      for(int i=1;i<nums.size();i++){
        int v1=last+nums[i];
        int v2=nums[i];
        last=max(v1,v2);
        sum=max(sum,last);
      }  
      return sum;
    }
};