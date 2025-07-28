class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

         vector<int> ans;
        for(int i=0;i<nums.size();i++){
            ans.push_back(nums[nums[i]]);
        }
        return ans;
    }
};