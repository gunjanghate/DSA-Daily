class Solution {
public:
    int minMoves2(vector<int>& nums) {

        sort(nums.begin(), nums.end());
        int n = nums.size();
        int med = nums[n/2];

        int ans = 0;

        for(int i = 0; i<n/2; i++){
            ans += abs(nums[i] - med);
        }
        for(int i = (n/2)+1; i<n; i++){
            ans += abs(nums[i] - med);

        }

        return ans;


        
    }
};