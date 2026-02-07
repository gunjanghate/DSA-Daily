class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int ans = INT_MAX;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        if(n==1) return 0;
        int mn = 0;
        int mx = 0;
        long long condition =(long long)k*nums[mn];
        for(int i = 1; i<n; i++){
            if(condition < nums[i]){
                mn++;
                condition = (long long) k*nums[mn]; 
            }
            if(condition >= nums[i]){
                mx = i;
                int rem = mn + n - 1 - mx;
                ans = min(ans, rem); 
            }
        }

        return ans;
    }
};