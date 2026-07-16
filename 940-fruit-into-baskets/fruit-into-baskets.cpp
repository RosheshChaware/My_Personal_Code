class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n=fruits.size();
        int high=0,low=0,res=INT_MIN;
        unordered_map<int,int>mpp;

        for(int high=0;high<n;high++){
            mpp[fruits[high]]++;

            while(mpp.size()>2){
                mpp[fruits[low]]--;
                if(mpp[fruits[low]]==0) mpp.erase(fruits[low]);
                low++;
            }
            if(mpp.size()==2 || mpp.size()<2){
                int len = high-low+1;
                res = max(res,len);
            }
        }
        return res;
    }
};