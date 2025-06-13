class Solution {
private:
    bool isPossiblePair(vector<int>& nums, int p, int m) {
        int noOfPairs = 0;
        for (int j = 0; j < nums.size() - 1; j++) {
            int diff = abs(nums[j] - nums[j + 1]);
            if (diff <= m) {
                noOfPairs++;
                j++;
            }
        }

        return noOfPairs >= p;
    }

public:
    int minimizeMax(vector<int>& nums, int p) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int l = 0;
        int mn = *min_element(nums.begin(), nums.end());
        int mx = *max_element(nums.begin(), nums.end());
        int h = mx - mn;
        int ans = 0;
        while (l <= h) {
            int m = l + (h - l) / 2;
            if (isPossiblePair(nums, p, m)) {
                ans = m;
                h = m - 1;
            } else {
                l = m + 1;
            }
        }

        return ans;
    }
};