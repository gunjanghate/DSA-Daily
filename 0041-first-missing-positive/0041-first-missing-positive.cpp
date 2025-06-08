class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        map<int, int> mp;
        for(auto i : nums) mp[i]++;
        if(!mp.count(1)){
            return 1;
        }
        int ans = INT_MAX;
        for(int i = 0;i<nums.size(); i++){
            if(nums[i]<=0) continue;
            if(nums[i] < INT_MAX && mp.count(nums[i]) != mp.count(nums[i]+1)){
                ans = min(ans,nums[i]+1);
            }
        }
        if(ans==-1) return nums.size();
        return ans;
        
    }
};