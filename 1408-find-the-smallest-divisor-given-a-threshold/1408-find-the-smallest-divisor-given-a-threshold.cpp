class Solution {
public:
    bool isPossible(vector<int>& nums, int threshold, int mid) {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            int p = ceil((double)nums[i] / mid);
            if (p < 1)
                sum++;
            else
                sum += p;
        }

        return sum <= threshold;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int l = 1;
        int h = *max_element(nums.begin(), nums.end());
        int m;
        int ans = h;
        while (l <= h) {
            m = l + (h - l) / 2;
            if (isPossible(nums, threshold, m)) {
                ans = m;
                h = m - 1;
            } else
                l = m + 1;
        }

        return ans;
    }
};