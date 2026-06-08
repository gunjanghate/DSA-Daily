class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(auto i : nums) mp[i]++;

        for(auto&[i,k] : mp){
            if(k==1) return i;
        }

        return -1;
    }
};