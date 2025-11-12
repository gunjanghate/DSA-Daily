class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ones = 0;
        for(int i : nums){
            if(i==1) ones++;
        }
        if(ones>0) return nums.size()-ones;

        int best = INT_MAX;

        for(int i = 0; i < nums.size(); i++) {
            int g = nums[i];
            for(int j = i + 1; j < nums.size(); j++) {
                g = __gcd(g, nums[j]);
                if(g == 1) {
                    best = min(best, j - i + 1);
                    break; 
                }
            }
        }

        // If never found gcd 1
        if(best == INT_MAX) return -1;
        return (best - 1) + (nums.size() - 1);
    }
};