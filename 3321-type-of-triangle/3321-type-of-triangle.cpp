class Solution {
public:
    string triangleType(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        unordered_map<int, int> mp;
        for (auto i : nums)
            mp[i]++;
        if ((nums[0] + nums[1]) > nums[2] && (nums[2] + nums[1]) > nums[0] &&
            (nums[0] + nums[2]) > nums[1]) {

            if (mp.size() == 1)
                return "equilateral";
            if (mp.size() == 2)
                return "isosceles";
            else
                return "scalene";
        }

        return "none";
    }
};