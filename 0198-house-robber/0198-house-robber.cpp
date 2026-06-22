class Solution {
public:
    int rob(vector<int>& nums) {
        int prev = nums[0];
        int prev1 = 0;
        for(int i = 1; i<nums.size(); i++){
            int pick = 0, notPick = 0;
            pick += nums[i];
            if(i>1) pick += prev1;
            notPick += prev;
            int curr = max(pick, notPick);
            prev1 = prev;
            prev = curr;
        }


        return prev;
    }
};