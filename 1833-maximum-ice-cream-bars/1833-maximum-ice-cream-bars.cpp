class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());

        int ans = 0;
        int sum = 0;

        for(auto cost : costs) {
            if(sum + cost > coins)
                break;

            sum += cost;
            ans++;
        }

        return ans;
    }
};