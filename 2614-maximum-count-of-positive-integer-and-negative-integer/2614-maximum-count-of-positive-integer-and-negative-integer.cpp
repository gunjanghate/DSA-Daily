class Solution {
    public:
    int maximumCount(std::vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n = nums.size();
        int left = 0;
        int  right = n - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > 0) {
                right = mid - 1; 
            } else {
                left = mid + 1; 
            }
        }
        int pos = n - left;


        left = 0; 
        right = n - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < 0) {
                left = mid + 1; 
            } else {
                right = mid - 1;
            }
        }
        int neg = right + 1;
        return max(pos, neg);
    }
};