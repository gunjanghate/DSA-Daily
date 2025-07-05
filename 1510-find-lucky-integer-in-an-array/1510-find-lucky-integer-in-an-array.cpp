class Solution {
public:
    int findLucky(vector<int>& arr) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        unordered_map<int, int> mp;
        int ans = -1;
        for(auto i : arr) mp[i]++;
        for(auto i : mp){
            if(i.first == i.second){
                ans = max(ans, i.first);
            }
        }

        return ans;
    }
};