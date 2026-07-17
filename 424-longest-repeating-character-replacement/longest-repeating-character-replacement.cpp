class Solution {
public:

int find(vector<int>&a){
int mcnt=-1;
for(int i=0;i<a.size();i++){
   mcnt=max(mcnt,a[i]); 
}

    return mcnt;
}

    int characterReplacement(string s, int k) {
        int high=0,low=0;
        int res=INT_MIN;

        vector<int>f(256,0);
        for(high=0;high<s.size();high++){
            f[s[high]]++;

           int mcnt = find(f);
            int len = high-low+1;
            int diff=len-mcnt;

            while(diff>k){
                f[s[low]]--;
                low++;

                mcnt=find(f);
                len =high-low+1;
                diff=len-mcnt;

            }
            len=high-low+1;
            res=max(res,len);

        }
        if(res==INT_MIN) return -1;
        else return res;
    }

};