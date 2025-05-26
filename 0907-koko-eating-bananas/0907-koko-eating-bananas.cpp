class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int l = 1, high = *max_element(piles.begin(), piles.end());
        int m;
        long long x = 0;
        int ans = high;
        while (l <= high) {
            m = l + (high - l) / 2;
            x= 0;
            for (int i = 0; i < piles.size(); i++) {
                x += ceil((double)piles[i] / m);
            }

            if (x <= h) {
                ans = m;
                high = m - 1;
            } else {
                l = m + 1;
            }
        }

        return ans;
    }
};