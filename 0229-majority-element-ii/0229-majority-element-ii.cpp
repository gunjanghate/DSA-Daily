class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int e1 = INT_MIN, e2 = INT_MIN;
        int c1 = 0, c2 = 0;

        for (int x : nums) {
            if (x == e1)
                c1++;
            else if (x == e2)
                c2++;
            else if (c1 == 0) {
                e1 = x;
                c1 = 1;
            } else if (c2 == 0) {
                e2 = x;
                c2 = 1;
            } else {
                c1--;
                c2--;
            }
        }

        c1 = c2 = 0;

        vector<int> res;
        int thre = nums.size() / 3;
        for (auto i : nums) {
            if (i == e1)
                c1++;
            if (i == e2)
                c2++;
        }

        if (c1 > thre)
            res.push_back(e1);
        if (c2 > thre)
            res.push_back(e2);

        return res;
    }
};