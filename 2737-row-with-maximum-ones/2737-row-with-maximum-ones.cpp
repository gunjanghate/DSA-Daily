class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int ansIndex = -1, maxOcc = INT_MIN;
        for(int i = 0; i<mat.size(); i++){
            int cnt = 0;
            for(int j = 0; j<mat[i].size(); j++){
                if(mat[i][j]==1) cnt++;
            }
            if(cnt>maxOcc){
                maxOcc = cnt;
            ansIndex = i;
            }
        } 

        return {ansIndex, maxOcc};
    }
};