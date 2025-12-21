

class Solution {
    // Function to find the leaders in the array.
  public:
    vector<int> leaders(vector<int>& arr) {
        // Code here
        vector<int> ans;
        if(arr.size()==0) return ans;
        int mx = -1;
        
        for(int i = arr.size()-1; i>=0; i--){
            if(arr[i] >= mx){
                mx = arr[i];
                ans.push_back(arr[i]);
            }
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};