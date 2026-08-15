class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int xr = 0;
        bool hasZero = false;
        int z = 0;

        for (auto i : nums) {
            xr ^= i;
            if (xr == 0) {
                hasZero = true; z++;
            };
        }

        if (xr != 0)
            return nums.size();

        if (hasZero)
         if(z==nums.size()) return 0; 
            return nums.size() - 1;

        return 0;
    }
};