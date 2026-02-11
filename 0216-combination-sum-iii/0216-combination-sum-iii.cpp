class Solution {
public:
    void solve(vector<vector<int>>& res, vector<int>& ans, int i, int k, int n, int total){
        
        if(ans.size() == k){
            if(total == n){
                res.push_back(ans);
            }
            return;
        }

        if(total > n) return;

        for(int a = i; a <= 9; a++){
            ans.push_back(a);
            solve(res, ans, a+1, k, n, total + a);
            ans.pop_back();
        }
    } 
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> temp;
        solve(res, temp, 1, k, n, 0);
        return res;
    }
};
