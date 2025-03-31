class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int ele1 = INT_MIN, ele2 = INT_MIN;
        int c1 = 0;
        int c2 = 0;
        int i = 0;
        while (i < nums.size()) {
            if (c1 == 0 && nums[i] != ele2) {
                ele1 = nums[i];
                c1++;
            } else if (c2 == 0 && nums[i] != ele1) {
                ele2 = nums[i];
                c2++;
            } else {

                if (ele1 == nums[i])
                    c1++;
                else if (ele2 == nums[i])
                    c2++;
                else {
                    c1--;
                    c2--;
                }
            }
            i++;
        }
        c1 = c2 = 0;
        for (int num : nums) {
            if (num == ele1)
                c1++;
            else if (num == ele2)
                c2++;
        }

        vector<int> result;
        int threshold = nums.size() / 3;
        if (c1 > threshold)
            result.push_back(ele1);
        if (c2 > threshold)
            result.push_back(ele2);

        return result;
    }
};