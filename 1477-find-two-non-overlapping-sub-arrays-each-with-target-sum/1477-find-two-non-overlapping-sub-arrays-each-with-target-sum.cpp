class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int k) {

        int i = 0, j = 0;
        int n = arr.size();
        int sum = 0;
        int lastMin = INT_MAX;
        int res = INT_MAX;

        vector<int> minTillidx(n, INT_MAX);
        while (j < n) {
            long long ans = 0;
            sum += arr[j];
            while (i<j && sum > k) {
                sum -= arr[i];
                i++;
            }
            if (sum == k) {
                int len = j - i + 1;
                lastMin = min(lastMin, len);
                if (i > 0) {
                    if (minTillidx[i - 1] != INT_MAX) {
                        res = min(res, minTillidx[i-1] + len);
                    }
                }
            }
            minTillidx[j] = lastMin;

            j++;
        }
        // for(auto i : minTillidx) cout<<i<<" ";

        return res == INT_MAX ? -1 : res;
    }
};