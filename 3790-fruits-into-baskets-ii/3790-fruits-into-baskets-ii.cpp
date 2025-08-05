class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        vector<bool> used(baskets.size(), false);
        int ans = 0;

        for (int fruit : fruits) {
            bool placed = false;
            for (int j = 0; j < baskets.size(); j++) {
                if (!used[j] && baskets[j] >= fruit) {
                    used[j] = true;
                    placed = true;
                    break;
                }
            }
            if (!placed) ans++;
        }
        return ans;
    }
};
