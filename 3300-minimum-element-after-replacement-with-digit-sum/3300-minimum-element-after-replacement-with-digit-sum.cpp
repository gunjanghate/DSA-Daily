class Solution {
public:
    int getSum(int n){
        int sum = 0;
        while(n>0){
            sum += n%10;
            n /= 10;
        }

        return sum;
    }
    int minElement(vector<int>& nums) {
        int ans = INT_MAX;
        for(int i : nums){
            ans = min(ans, getSum(i));
        }

        return ans;
    }
};