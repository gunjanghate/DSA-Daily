class Solution {
public:
    int countAtMost(vector<int>& nums, int k) {
    
        int left = 0;
        int sum = 0;
        int count = 0;
        for (int right = 0; right < nums.size(); right++) {
            sum += nums[right]%2==0? 0 : 1;
            while (sum > k) {
                sum -= nums[left]%2==0? 0 : 1;
                left++;
            }

            count += (right - left + 1);
        }

        return count;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return countAtMost(nums, k) - countAtMost(nums, k - 1);
    }
};