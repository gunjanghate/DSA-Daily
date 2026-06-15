class Solution {
public:
    int maxScore(vector<int>& c, int k) {
        int n = c.size();
        if(n==k) return accumulate(c.begin(), c.end(), 0);

        int ls = 0, rs = 0;
        for(int i = 0; i<k; i++){
            ls += c[i];
        }
        int ans = ls;
        int j = n - 1;
        int total = ls;
        while(k){
            total -= (k-1>=0 ? c[k-1] : c[0]);
            total += c[j];
            ans = max(ans, total); 
            k--;
            j--;
        }

        return ans;
    }
};