class Solution {
public:
    int maxEqualAdjacentPairs(vector<int>& nums) {
        int n = nums.size();

        int base = 0;

        map<pair<int, int>, int> mp;

        for(int i = 1; i<n; i++){
            if(nums[i]==nums[i-1]) base++;
            else{
                int x = min(nums[i], nums[i-1]);
                int y = max(nums[i], nums[i-1]);

                mp[{x, y}]++;
            }
        }

        int maxans = 0;

        for(auto &it: mp){
            maxans = max(maxans, it.second);
        } 


        return base + maxans;
    }
};