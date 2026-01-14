class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        map<int, int> freq;
        for (auto n : nums) freq[n]++;
        int rem = k;

        vector<pair<int,int>> arrOfPairs;
        for(auto p : freq){
            arrOfPairs.push_back({p.first, p.second});
        }

        sort(arrOfPairs.begin(), arrOfPairs.end(), [](auto &a, auto &b){
            return a.second>b.second;
        });

        vector<int> ans;
        for(auto i : arrOfPairs){
            if(rem!=0){
                ans.push_back(i.first);
                rem--;
            }
        }
        return ans;
    }
};