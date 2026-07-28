class Solution {
public:
    unordered_map<string, bool> dp;

    bool solve(string s1, string s2) {
        string key = s1 + "#" + s2;

        if(dp.count(key)) return dp[key];
        if(s1==s2) return dp[key] = true;

        if(s1.length() != s2.length()) return dp[key] = false;

        string a = s1, b = s2;

        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        if(a!=b) return dp[key] = false;
        int n = s1.length();

        for(int i = 1; i<n ; i++){
            if(solve(s1.substr(0,i) , s2.substr(0,i)) && solve(s1.substr(i) , s2.substr(i)))
                return dp[key] = true;

            if(solve(s1.substr(0,i) , s2.substr(n-i)) && solve(s1.substr(i) , s2.substr(0, n-i)))
                return dp[key] = true;
        }

        return dp[key] = false;
    }

    bool isScramble(string s1, string s2) {
        return solve(s1, s2);
    }
};