class Solution {
public:
    int getDigSum(int x) {
        int num = x, sum = 0;
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }
    int minSwaps(vector<int>& nums) {
        unordered_map<int, int> mp;
        vector<int> nums2(nums);

        int ans = 0;
        int n = nums.size();
        auto lamda =
            [&](int num1, int num2) {
                int dnum1 = getDigSum(num1);
                int dnum2 = getDigSum(num2);

                if (dnum1 == dnum2) {
                    return num1 < num2;
                }

                return dnum1 < dnum2;
            };

        sort(nums2.begin(), nums2.end(), lamda); // nlogn * n

        for (int i = 0; i < n; i++) {
            mp[nums[i]] = i;
        }

        int swap = 0;

        for (int i = 0; i < n; i++) {
            if (i == mp[nums2[i]])
                continue;
            int idx = mp[nums2[i]];
            int curr = nums[i];
            nums[i] = nums2[i];
            nums[idx] = curr;

            mp[curr] = idx;
            mp[nums2[i]] = i;
            swap++;
        }

        return swap;
    }
};