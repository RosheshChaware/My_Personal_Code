class Solution {
public:
    int maxProduct(vector<int>& nums) {
     int product=nums[0];
     int lastmax=nums[0];
     int lastmin=nums[0];

     for(int i=1;i<nums.size();i++){
        int v1=nums[i];
        int v2=lastmin*nums[i];
        int v3=lastmax*nums[i];

        lastmax=max(v1,max(v2,v3));
        lastmin=min(v1,min(v2,v3));
             product=max(product,lastmax);
     }   
     return product;
    }
};