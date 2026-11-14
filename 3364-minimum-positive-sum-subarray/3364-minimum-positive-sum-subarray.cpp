class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int ans = INT_MAX;
        int n = nums.size();

        bool isPositive = false;


        for(int k = l; k<=r; k++){

            int sum = 0;

            int i = 0;
            while(i<k){
                sum += nums[i];
                i++;
            }
            if(sum>0) ans = min(ans, sum), isPositive = true;

            while(i<n){
                sum -= nums[i-k];
                sum += nums[i];
                if(sum>0) ans = min(ans, sum), isPositive = true;
                i++;
            }
        }

        if(!isPositive) return -1;

        return ans;
        
    }
};