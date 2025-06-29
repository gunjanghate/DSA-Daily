class Solution {
public:
    int heightChecker(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        vector<int> expected(nums.begin(), nums.end());
        sort(nums.begin(), nums.end());
        int cnt = 0;

        for(int i = 0; i<nums.size(); i++){
            if(nums[i]!=expected[i]) cnt++;
        }

        return cnt;
        
    }
};