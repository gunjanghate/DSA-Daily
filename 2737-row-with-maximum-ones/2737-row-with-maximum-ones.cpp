class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int row = 0, maxcnt = 0;
        for(int i = 0, n = mat.size(); i < n; ++i){
            int count = accumulate(mat[i].begin() , mat[i].end() , 0);
            if(count > maxcnt){
                row = i;
                maxcnt = count;
            }
        }
        return {row , maxcnt};
    }
};