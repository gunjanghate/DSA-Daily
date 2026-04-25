class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int ans = 0;
        int i = 0, j = 0;
        while(j<s.size()){
            if(i==g.size()) break;
            if(g[i]<=s[j]){
            ans++;
            i++;
            j++;
            } 
            else j++;
        }


        return ans;
    }
};