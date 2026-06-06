class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int, int> mp({{0, 1}});
        int c = 0;
        int res = 0;
        for(int i = 0; i<nums.size(); i++){
            c += nums[i]%2!=0 ? 1: 0;
            res += mp[c - k];
            mp[c]++;
        }

        return res;
    }
};