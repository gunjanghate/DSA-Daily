class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
       unordered_map<int, int> mp;
        mp[0]=1;
        int ps = 0, c = 0;
        for(int i = 0; i< nums.size(); i++){
            ps += nums[i];
            int remove = ps - k;
            c += mp[remove];
            mp[ps]++;
        }
        return c;
    }
};