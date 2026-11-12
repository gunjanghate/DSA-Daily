class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {

        int inc = 1, dec = 1, ans = 1;
        int n = nums.size();
        for(int i = 1; i<n; i++){
            if(nums[i-1]<nums[i]) inc++, dec = 1;
            else if(nums[i-1]>nums[i]) dec++, inc = 1;
            else inc=1, dec=1;

            ans = max(ans, max(inc, dec));
        }

        return ans;
        
    }
};