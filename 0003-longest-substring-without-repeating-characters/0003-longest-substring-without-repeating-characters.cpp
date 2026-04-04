class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> st;
        int i = 0, j = 0;
        int mx = 0;

        while (i < s.length()) {
            while (st.find(s[i]) != st.end()) {
                st.erase(s[j]);
                j++;
            }

            st.insert(s[i]);
            mx = max(mx, i - j + 1);  
            i++;
        }

        return mx;
    }
};