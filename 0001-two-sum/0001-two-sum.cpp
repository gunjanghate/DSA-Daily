class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        map<int, int> mp;
        for(int i = 0; i<nums.size(); i++){
            int current = nums[i];
            int more = (k - current);
            if(mp.find(more)!=mp.end()) {
                return {mp[more], i};
            }
            mp[nums[i]]=i;
        }

        return {-1,-1};
    }
};