class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        bool inc1 = false;
        bool dec = false;
        bool inc2 = false;
        for (int i = 0; i < nums.size() - 1; i++) {

            if (nums[i] == nums[i + 1])
                return false;

            if (!dec && !inc2 && nums[i] < nums[i + 1]) {
                inc1 = true;
            } else if (nums[i] > nums[i + 1]) {
                if (!inc1)
                    return false;
                if (inc2)
                    return false;
                dec = true;
            } else if (dec && nums[i] < nums[i + 1]) {
                inc2 = true;
            }
        }

        return inc1 && dec && inc2;
    }
};
