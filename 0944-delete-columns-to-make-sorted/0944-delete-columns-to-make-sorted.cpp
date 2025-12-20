class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        int c = 0;
        int n = strs[0].length();
        int m = strs.size();

        for(int i = 0; i<n ; i++){
            for(int j = 0; j < m - 1; j++){
                if(strs[j][i] > strs[j+1][i]){
                    c++;
                    break;
                }
            }
        }

        return c;

    }
};