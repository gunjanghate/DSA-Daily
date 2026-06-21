class Solution {
public:
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        int n = val.size();

        vector<pair<double, int>> items;

        for(int i = 0; i < n; i++) {
            items.push_back({(double)val[i] / wt[i], i});
        }

        sort(items.begin(), items.end(),
             [](auto &a, auto &b) {
                 return a.first > b.first;
             });

        double profit = 0.0;

        for(auto &item : items) {
            int idx = item.second;

            if(wt[idx] <= capacity) {
                profit += val[idx];
                capacity -= wt[idx];
            } else {
                profit += item.first * capacity;
                break;
            }
        }

        return profit;
    }
};