class Solution {
public:
    int reverseDigits(int num) {
        int rev = 0;
        while (num > 0) {
            rev = rev * 10 + (num % 10);
            num /= 10;
        }
        return rev;
    }

    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int, int> mp; 
        int ans = INT_MAX;

        for (int j = 0; j < nums.size(); j++) {
            if (mp.find(nums[j]) != mp.end()) {
                ans = min(ans, j - mp[nums[j]]);
            }


            int rev = reverseDigits(nums[j]);
            mp[rev] = j;
        }

        return (ans == INT_MAX ? -1 : ans);
    }
};