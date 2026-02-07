class Solution {
public:
    int minimumDeletions(string s) {
          ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int cnt=0;
        int res=0;
        for(int i=0; i<s.size(); i++){
                if(s[i]=='b') cnt++;
                else if(s[i]=='a' && cnt!=0){
                    cnt--;
                    res++;
                }
               
        }
        return res;
    }
};