// User function template for C++

class Solution {
  public:
    int helper(vector<int>& arr, int m, int n, int k){
        int painters = 1;
        int noOfwalls = 0;
        for(int i = 0; i<n; i++){
            if((arr[i]+noOfwalls)<=m) noOfwalls+=arr[i];
            else{
                painters++;
                noOfwalls= arr[i];
            }
        }
        return painters;
    }
    int minTime(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        int l = *max_element(arr.begin(), arr.end());
        int h = accumulate(arr.begin(), arr.end(), 0);
        int m, ans = h;
        while(l<=h){
            m = l + (h-l)/2;
            int res = helper(arr,m,n,k);
            if(res<=k){
                ans = m;
                h = m-1;
            }else l = m+1;
        }
        
        return ans;
        
        // return minimum time
    }
};