class Solution {
public:
    unordered_map<int, long long> memo;
    long long solve(vector<vector<int>>& questions, int i) {
        if (i >= questions.size())
            return 0;
        if (memo.find(i) != memo.end())
            return memo[i];

        long long take =
            questions[i][0] + solve(questions, i + questions[i][1] + 1);
        long long skip = solve(questions, i + 1);

        return memo[i] = max(take, skip);
    }

    long long mostPoints(vector<vector<int>>& questions) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        return solve(questions, 0);
    }
};
