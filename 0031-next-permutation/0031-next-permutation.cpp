class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int ind = -1;
        int n = nums.size();
        for (int i = n - 2; i >= 0; i--) { //checking from back for breakpoint
            if (nums[i] < nums[i + 1]) {
                ind = i;
                break;
            }
        }
        if (ind == -1) {
            reverse(nums.begin(), nums.end()); //no breakpoint means next permuation is first sequence
            return;
        }
        for (int i = n - 1; i >= ind; i--) {
            if (nums[i] > nums[ind]) {
                swap(nums[i], nums[ind]);
                break;
            }
        }
        reverse(nums.begin() + ind + 1, nums.end());
    }
};