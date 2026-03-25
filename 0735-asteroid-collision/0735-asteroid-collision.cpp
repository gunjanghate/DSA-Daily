class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a) {
        vector<int> ans;

        for (int i = 0; i < a.size(); i++) {
            bool destroyed = false;

            while (!ans.empty() && ans.back() > 0 && a[i] < 0) {
                if (ans.back() < abs(a[i])) {
                    ans.pop_back();
                }
                else if (ans.back() == abs(a[i])) {
                    ans.pop_back();
                    destroyed = true;
                    break;
                }
                else {
                    destroyed = true;
                    break;
                }
            }

            if (!destroyed) {
                ans.push_back(a[i]);
            }
        }

        return ans;
    }
};