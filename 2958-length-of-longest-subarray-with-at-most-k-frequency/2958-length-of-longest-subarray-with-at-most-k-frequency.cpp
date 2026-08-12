class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 0;
        unordered_map<int, int> mp;
        int ans = INT_MIN;
        for(int i = 0; i<n; i++){
            mp[nums[i]]++;

            while(mp[nums[i]]>k && l < n){
                mp[nums[l]]--;
                l++;
            }

            ans = max(ans, i - l + 1);
        }

        return ans;
    }
};