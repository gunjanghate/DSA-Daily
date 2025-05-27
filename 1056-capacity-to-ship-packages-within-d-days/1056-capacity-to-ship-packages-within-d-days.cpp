class Solution {
public:
    bool isPossible(vector<int>& weights, int days, int m){
        int wcnt = m;
        int dcnt = 1; 

        for(int i = 0; i<weights.size(); i++){
            if (weights[i] > m)
                return false;
            if((wcnt - weights[i])<0){
                dcnt++;
                wcnt = m;
            }
            wcnt -= weights[i];
        }
        return dcnt<=days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int l = 1;
        int h = accumulate(weights.begin(), weights.end(),0);
        int m;
        int ans = h;
        while (l <= h) {
            m = l + (h - l) / 2;
            if (isPossible(weights, days, m)) {
                ans = m;
                h = m - 1;
            } else
                l = m + 1;
        }

        return ans;

    }
};