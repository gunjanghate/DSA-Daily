
class Solution {
public:
    int longestSubarray(std::vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        int maxVal = 0;
        for (int num : nums) {
            if (num > maxVal) {
                maxVal = num;
            }
        }
        int maxLen = 0;
        int currentLen = 0;\
        // a & b <= min(a, b)
        // It means the the maxm value of bitwise and will bitwose and of maxVal of complete nums array
        // So, the maximum possible bitwise AND value for any subarray is simply the maximum value present in the entire nums array.
        
        for (int num : nums) {
            if (num == maxVal) {
                currentLen++;
            } else {
                maxLen = max(maxLen, currentLen);
                currentLen = 0;
            }
        }

        return max(maxLen, currentLen);
    }
};