class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int c1 = 0, c2 = 0;
        int ans = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                c2++; 
            } else {
                ans = max(ans, c1 + c2); 
                c1 = c2;  
                c2 = 0;  
            }
        }

        ans = max(ans, c1 + c2);

        if (ans == nums.size()) ans--;

        return ans;
    }
};
