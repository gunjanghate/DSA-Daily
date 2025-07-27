class Solution {
public:
    int countHillValley(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int cnt = 0;
        for (int i = 1; i < nums.size() - 1; i++) {

            if (nums[i] == nums[i - 1]) continue;
            int leftNonEQ, rightNonEQ;
            int p = i - 1;
            while (p >= 0 && nums[p] == nums[i]) {
                p--;
            }
            leftNonEQ = (p >= 0 ? nums[p] : nums[i]);
            p = i + 1;
            while (p < nums.size() && nums[p] == nums[i]) {
                p++;
            }
            rightNonEQ = (p < nums.size() ? nums[p] : nums[i]);
            int curr = nums[i];
            if ((curr > leftNonEQ && curr > rightNonEQ) ||
                (curr < leftNonEQ && curr < rightNonEQ)) {
                cnt++;
            }
        }

        return cnt;
    }
};