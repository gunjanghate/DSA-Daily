class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        vector<int> freq(100001, 0);
        int fmx = 0;

        for (int cost : costs) {
            freq[cost]++;
            fmx = max(fmx, cost);
        }

        int ans = 0;

        for (int price = 1; price <= fmx && coins > 0; price++) {
            if (freq[price] == 0)
                continue;

            int canBuy = min(freq[price], coins / price);

            ans += canBuy;
            coins -= canBuy * price;
        }

        return ans;
    }
};