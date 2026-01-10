class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        vector<vector<int>> res;
        vector<int> ans;
        solve(0, candidates, target, 0 , ans, res);
        return res;
    }
private:
    void solve(int i, vector<int>& candidates, int target, int total, vector<int> &ans, vector<vector<int>> &res){
        if(total==target){
            res.push_back(ans);
            return;
        }
        if( target<total || i>=candidates.size() ){
            return;
        }
        
        ans.push_back(candidates[i]);
        // pick
        solve(i, candidates, target, total+candidates[i] , ans, res);
        ans.pop_back();

        // not pick
        solve(i+1, candidates, target, total , ans, res);

        
    } 

};