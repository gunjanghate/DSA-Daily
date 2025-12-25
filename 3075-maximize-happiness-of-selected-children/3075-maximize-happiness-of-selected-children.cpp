class Solution {
public:
    long long maximumHappinessSum(vector<int>& h, int k) {
        sort(h.begin(), h.end(), greater<int>());
        long long ans = 0;
        for (int i = 0; i < k; i++) {
            ans += max(h[i] - i, 0);
        }

        return ans;
    }
};