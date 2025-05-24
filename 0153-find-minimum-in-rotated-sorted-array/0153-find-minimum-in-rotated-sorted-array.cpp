class Solution {
public:
    int findMin(vector<int>& arr) {
        int n = arr.size();
        int l = 0, h = n - 1;
        int m;
        int ans = INT_MAX;
        while (l <= h) {
            m = l + (h - l) / 2;
            if (arr[l] <= arr[h]) {
                ans = min(ans, arr[l]);
                break;
            }
            if (arr[m] >= arr[l]) {
                ans = min(ans, arr[h]);
                l = m + 1;
            } else {
                ans = min(ans, arr[m]);
                h = m - 1;
            }
        }
        return ans;
    }
};