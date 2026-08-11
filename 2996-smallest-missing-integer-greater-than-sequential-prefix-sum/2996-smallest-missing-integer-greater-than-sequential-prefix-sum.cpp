class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();

        int sum = nums[0];
        vector<bool> exists(52, false);

        for(auto i : nums){
            exists[i] = true;
        }

        for (int i = 1; i < n; i++) {
            if (nums[i] == nums[i - 1] + 1)
                sum += nums[i];
            else
                break;
        }

        if(sum>50) return sum;

        for(int i = sum; i<=52; i++){
            if(!exists[i]) return i;
        }

        return 0;
    }
};