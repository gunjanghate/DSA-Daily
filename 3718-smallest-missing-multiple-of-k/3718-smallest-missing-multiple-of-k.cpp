class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> st(nums.begin(), nums.end());
        int i = 1;
        while (true) {
            int x = k * i;
            if (st.find(x) == st.end()) {
                return x;
            }
            ++i;
        }
    }
};