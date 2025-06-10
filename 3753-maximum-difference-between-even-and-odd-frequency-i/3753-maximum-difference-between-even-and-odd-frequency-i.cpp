class Solution {
public:
    int maxDifference(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        unordered_map<char, int> mp;
        for (auto i : s)
            mp[i]++;
        int maxOdd = INT_MIN, maxEven = INT_MAX;          
        
        for (auto i : mp) {
            if (i.second % 2 != 0) {
                maxOdd = max(maxOdd, i.second);
            } 
            if(i.second % 2 ==0 && i.second>0) {
                maxEven = min(maxEven, i.second);
            }
        }

        return (maxOdd - maxEven);
    }
};