class Solution {
  public:
    // Function to check if b is a subset of a
    bool isSubset(vector<int> &a, vector<int> &b) {
        // Your code here
        if(a.size()<b.size()) return false;
        unordered_map<int, int> mp;
        
        for(auto i : a) mp[i]++;
        
        for(auto i : b){
            if(!mp[i]) return false;
            mp[i]--;
        }
        return true;
    }
};