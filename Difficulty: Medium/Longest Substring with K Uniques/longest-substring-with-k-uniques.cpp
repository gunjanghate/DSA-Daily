class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        // code here
        unordered_map<int , int>mp;
        int n = s.length();
        int i = 0; 
        int j =0;
        int ans = -1;
        
        
        while(j<n){
            mp[s[j]]++;
            while(mp.size()>k){
                mp[s[i]]--;
                if(mp[s[i]]==0){
                    mp.erase(s[i]);
                }
                i++;
            }
            if(mp.size()==k){
            ans = max(ans, j - i + 1);
                
            }
            j++;
        }
        
        
        return ans;
    }
};