class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end(), [](auto &a, auto& b){
            if(a[0]==b[0]){
                return a[1] > b[1];
            }else{
                return a[0] < b[0];
            }
        });
        for(auto i : intervals){
            if(!ans.empty() && ans.back()[0]<=i[0] && ans.back()[1]>=i[1]){
                continue;
            }
            else{
               ans.push_back(i); 
            }
        }

        return ans.size();
    }
};