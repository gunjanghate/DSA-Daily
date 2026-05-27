class Solution {
  public:
    vector<int> prefSum(vector<int> &arr) {
        // code here
        vector<int> ans(arr.size(),0);
        int sum = arr[0];
        
        ans[0]= sum;
        for(int i = 1; i<arr.size(); i++){
            sum += arr[i];
            ans[i] = sum;
        }
        
        return ans;
    }
};