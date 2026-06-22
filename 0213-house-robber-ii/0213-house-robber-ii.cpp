class Solution {
public:
    int solve(vector<int>& nums) {
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
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> t1, t2;
        if(n==1) return nums[0];

        for(int i = 0; i<n; i++){
            if(i!=0) t1.push_back(nums[i]);
            if(i!=n-1) t2.push_back(nums[i]);
        }

        return max(solve(t1), solve(t2));
        
    }
};