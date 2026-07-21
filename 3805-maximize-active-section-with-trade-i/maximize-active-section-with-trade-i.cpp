class Solution{
public:
    int maxActiveSectionsAfterTrade(string s){
        int n=s.size();
        int cnt=0;

        for(int i=0;i<n;i++){
            if(s[i]=='1')
                cnt++;
        }

        s="1"+s+"1";

        int ans=cnt;
        int i=1;

        while(i<=n){
            if(s[i]=='1'){
                int l=i;

                while(i<=n&&s[i]=='1')
                    i++;

                int r=i;

                if(l>1&&r<=n){
                    int left=l-1;

                    while(left>=0&&s[left]=='0')
                        left--;

                    int right=r;

                    while(right<n+2&&s[right]=='0')
                        right++;

                    ans=max(ans,cnt+(l-left-1)+(right-r));
                }
            }
            else{
                i++;
            }
        }

        return ans;
    }
};