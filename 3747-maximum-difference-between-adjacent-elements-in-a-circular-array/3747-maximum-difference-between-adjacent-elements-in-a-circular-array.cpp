class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int ans = INT_MIN;
        int n = nums.size();
        for(int i = 0; i<n; i++){
            ans = max(ans, abs(nums[i%n]-nums[(i+1)%n]));
        }

        return ans;
    }
};