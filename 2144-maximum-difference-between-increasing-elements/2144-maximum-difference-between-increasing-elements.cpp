class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n = nums.size();
        int i = 0, j = 1;
        int mxDiff = -1;
        while (j < n) {
            if (nums[i] < nums[j]) {
                mxDiff = max(mxDiff, (nums[j] - nums[i]));
            }else {
                i = j; 
            }
            j++; 
        }
        return mxDiff;
    }
};