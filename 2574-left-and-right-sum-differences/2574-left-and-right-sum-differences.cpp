class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        int left = 0;
        vector<int> ans;
        for(int i = 0; i<nums.size(); i++){
            int right = total - left - nums[i];
            ans.push_back(abs(left-right));
            left += nums[i];
             
        }
        return ans;
    }
};