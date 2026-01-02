class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_map<int, int> mp;
        int n = nums.size()/2;
        for(auto i : nums) mp[i]++;

        for(auto m : mp){
            if(m.second==n){
            return m.first;

            }
        }


        return -1;
    }
};