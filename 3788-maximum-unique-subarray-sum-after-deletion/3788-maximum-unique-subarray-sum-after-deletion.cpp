class Solution {
public:
    int maxSum(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int maxElement = *max_element(nums.begin(), nums.end());
        if (maxElement < 0) return maxElement;

        unordered_set<int> uniqueNonNeg;
        for (int n : nums) {
            if (n >= 0) uniqueNonNeg.insert(n);
        }

        int sum = 0;
        for (int n : uniqueNonNeg) sum += n;
        return sum;
    }
};
