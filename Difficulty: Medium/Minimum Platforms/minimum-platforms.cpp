class Solution {
  public:
    int minPlatform(vector<int>& arr, vector<int>& dep) {
        // code here
       sort(arr.begin(), arr.end());
       sort(dep.begin(), dep.end());
       
       int i = 0, j = 0;
       int pf = 0;
       int ans = -1;
       
       while(i<arr.size() && j < dep.size()){
           if(arr[i]<=dep[j]){
               pf++;
               ans = max(ans, pf);
               i++;
           }
           else{
               pf--;
               j++;
           }
       }
        
        
        return ans;
        
        
    }
};
