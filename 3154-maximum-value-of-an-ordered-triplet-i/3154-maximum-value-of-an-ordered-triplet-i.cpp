class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        long long mx = 0;
        long long value = 0;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 1 + i; j < nums.size(); j++) {

                for (int k = 1 + j; k < nums.size(); k++) {
                    value = (1LL *(nums[i]-nums[j]))*nums[k];
                    mx = max(mx, value);
                }

            }
        }
        

        return mx;
    }
};