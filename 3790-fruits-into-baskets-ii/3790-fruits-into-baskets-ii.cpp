class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int ans = 0;

        for (int fruit : fruits) {
            bool placed = false;
            for (int &basket : baskets) {
                if (basket != -1 && basket >= fruit) {
                    basket = -1;   
                    placed = true;
                    break;
                }
            }
            if (!placed) ans++;
        }
        return ans;
    }
};
