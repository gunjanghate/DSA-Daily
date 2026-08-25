class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> st(nums.begin(), nums.end());
        int i = k;
        while (true) {
            if (st.find(i) == st.end()) {
                return i;
            }
            i+=k;
        }
    }
};