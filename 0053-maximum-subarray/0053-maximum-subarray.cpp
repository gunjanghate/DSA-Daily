class Solution {
public:
    int maxSubArray(vector<int>& nums) {
    ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int mx = INT_MIN;
        int s = 0;
        for (int i = 0; i < nums.size(); i++) {
            s += nums[i];
            mx = max(s, mx);
            if (s < 0) {
                s = 0;
            } 
        }
        return mx;
    }
};