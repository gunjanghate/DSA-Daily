class Solution {
public:
    vector<vector<int>> filterOccupiedIntervals(vector<vector<int>>& ocInt,
                                                int fs, int fe) {

        if (ocInt.empty()) return {};

        sort(ocInt.begin(), ocInt.end());

        vector<vector<int>> merged;

        for (auto &in : ocInt) {
            if (merged.empty() || in[0] > merged.back()[1]+1) {
                merged.push_back(in);
            } else {
                merged.back()[1] = max(merged.back()[1], in[1]);
            }
        }

        vector<vector<int>> ans;

        for (auto &in : merged) {

            // No overlap
            if (in[1] < fs || in[0] > fe) {
                ans.push_back(in);
            }
            // Interval completely inside [fs, fe]
            else if (in[0] >= fs && in[1] <= fe) {
                continue;
            }
            // Overlap on the left
            else if (in[0] < fs && in[1] <= fe) {
                ans.push_back({in[0], fs - 1});
            }
            // Overlap on the right
            else if (in[0] >= fs && in[1] > fe) {
                ans.push_back({fe + 1, in[1]});
            }
            // Interval spans across [fs, fe]
            else {
                ans.push_back({in[0], fs - 1});
                ans.push_back({fe + 1, in[1]});
            }
        }

        return ans;
    }
};