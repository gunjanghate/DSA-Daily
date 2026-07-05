class Solution {
public:
    const int MOD = 1e9 + 7;

    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size();

        vector<vector<int>> score(n, vector<int>(n, -1));
        vector<vector<int>> ways(n, vector<int>(n, 0));

        score[0][0] = 0;
        ways[0][0] = 1;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {

                if (board[i][j] == 'X')
                    continue;

                if (i == 0 && j == 0)
                    continue;

                int best = -1;
                long long cnt = 0;

                vector<pair<int,int>> prev = {
                    {i-1,j},
                    {i,j-1},
                    {i-1,j-1}
                };

                for(auto [x,y] : prev){

                    if(x < 0 || y < 0)
                        continue;

                    if(score[x][y] == -1)
                        continue;

                    if(score[x][y] > best){
                        best = score[x][y];
                        cnt = ways[x][y];
                    }
                    else if(score[x][y] == best){
                        cnt = (cnt + ways[x][y]) % MOD;
                    }
                }

                if(best == -1)
                    continue;

                int val = 0;

                if(board[i][j] >= '1' && board[i][j] <= '9')
                    val = board[i][j] - '0';

                score[i][j] = best + val;
                ways[i][j] = cnt % MOD;
            }
        }

        if(ways[n-1][n-1] == 0)
            return {0,0};

        return {score[n-1][n-1], ways[n-1][n-1]};
    }
};