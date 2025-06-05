class Solution {
public:
    //taking help from painters partiton/ book allocation as these having same approach but different problem statements

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
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
       
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
      
    }

    int splitArray(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        return minTime(nums, k);
    }
};