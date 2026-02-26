class Solution {
public:
    bool areWeGoingGood(string& s, string& word) {
        if (s.length() > word.length())
            return false;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] != word[i]) {
                return false;
            }
        }
        return true;
    }

    void solve(bool& ans, int row, int col, vector<vector<char>>& board,
               string& word, string s, vector<vector<bool>>& visited) {

        // base conditions

        if (row < 0 || col < 0 || row >= board.size() ||
            col >= board[0].size() || visited[row][col]) {
            return;
        }

        s += board[row][col];

        if (!areWeGoingGood(s, word)) {
            return;
        }

        if (s.length() == word.length()) {
            ans = true;
            return;
        }

        visited[row][col] = true;

        // recursion logic

        solve(ans, row + 1, col, board, word, s, visited);
        solve(ans, row - 1, col, board, word, s, visited);
        solve(ans, row, col + 1, board, word, s, visited);
        solve(ans, row, col - 1, board, word, s, visited);

        visited[row][col] = false; // backtrack
    }

    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int cols = board[0].size();

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {

                vector<vector<bool>> visited(rows, vector<bool>(cols, false));
                bool ans = false;
                solve(ans, i, j, board, word, "", visited);

                if (ans)
                    return true;
            }
        }

        return false;
    }
};