class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int ans = 0;
        int i = 0, j = 0;

        vector<int> diffs;
        int n = s.length();
        for(int i = 0; i<n; i++){
            diffs.push_back(abs(s[i]-t[i]));
        }

        int cost = 0;

        while(j<n){
            cost+=diffs[j];
            j++;
            while(cost > maxCost){
                cost -= diffs[i];
                i++;
            }


            ans = max(ans, j - i + 1);
        }

        return ans -1;
    }
};