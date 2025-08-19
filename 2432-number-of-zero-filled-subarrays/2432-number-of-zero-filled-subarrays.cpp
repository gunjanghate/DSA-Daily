class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int l = 0;
        int n = nums.size();
        int curr = -1;
        int prev = -1;
        long long ans = 0;  
        for(int i = 0; i < n; i++) {
            prev = curr;
            curr = nums[i];

            if(curr == 0 && prev != 0) {
                l = 1;  
            } else if(prev == curr && curr == 0) {
                l++;
            } else {
                ans += 1LL * l * (l + 1) / 2;
                l = 0;
            }
        }

        ans += 1LL * l * (l + 1) / 2;

        return ans;
    }
};
