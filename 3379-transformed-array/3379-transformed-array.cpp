class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);

        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                result[i] = nums[i];
            } else {
                int newIndex = (i + nums[i]) % n;
                if (newIndex < 0) newIndex += n;
                result[i] = nums[newIndex];
            }
        }
        return result;
    }
};
