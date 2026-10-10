
class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1,
                               vector<int>& nums2,
                               int k1, int k2) {
        int n = nums1.size();

        int maxDiff = 0;
        for (int i = 0; i < n; i++) {
            maxDiff = max(maxDiff,
                          abs(nums1[i] - nums2[i]));
        }

        vector<int> countDiff(maxDiff + 1, 0);

        for (int i = 0; i < n; i++) {
            int d = abs(nums1[i] - nums2[i]);
            countDiff[d]++;
        }

        long long K = 1LL * k1 + k2;

        for (int i = maxDiff; i > 0 && K > 0; i--) {
            int ops = min((long long)countDiff[i], K);

            countDiff[i] -= ops;
            countDiff[i - 1] += ops;

            K -= ops;
        }

        long long ans = 0;

        for (int i = 1; i <= maxDiff; i++) {
            ans += 1LL * countDiff[i] * i * i;
        }

        return ans;
    }
};
