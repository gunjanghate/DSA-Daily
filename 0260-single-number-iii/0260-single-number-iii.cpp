class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xr = 0;
        for(int i = 0; i<nums.size(); i++){
            xr ^= nums[i];
        }
        long long x = (long long)xr & (-(long long)xr);
        int first = 0, sec = 0;
        for(int i =0; i<nums.size(); i++){
            if(nums[i] & x){
                first ^= nums[i];
            } else
                sec ^= nums[i];
        }

        return {first, sec};

    }
};