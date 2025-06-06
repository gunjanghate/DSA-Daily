class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        map <int, int> mp;
        for(auto i: nums) mp[i]++;

        int cnt = 0;
        for(auto it = mp.rbegin(); it != mp.rend(); ++it){
            cnt+=it->second;
            if(cnt>=k) return it->first;
        }

        return -1;
        
    }
};