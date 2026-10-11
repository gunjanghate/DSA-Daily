class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int n = nums.size();
        long long sum =0;
        for(int i = 1; i<=n; i++){
            if(n%i==0){
                sum += 1LL*(nums[i-1]*nums[i-1]);
            }
        }

        return sum;
    }
};