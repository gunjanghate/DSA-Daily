class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();

        int ans = 0;
        int mx = *max_element(nums.begin(), nums.end());

        for(int i = 0; i<n; i++){
            if(nums[i]!=mx) ans += abs(nums[i] - mx);
        }

        

        return ans;     
    }
};