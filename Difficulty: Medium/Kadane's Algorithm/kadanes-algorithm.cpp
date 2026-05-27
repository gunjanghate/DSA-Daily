class Solution {
  public:
    int maxSubarraySum(vector<int> &arr) {
        // Code here
        int sum =0;
        int ans = INT_MIN;
        for(int i = 0; i<arr.size(); i++){
            if(sum<=0){
                sum = 0;
            }
            sum+=arr[i];
            ans = max(ans, sum);
        }
        
        return ans;
    }
};