class Solution {
public:
    int numOfSubarrays(std::vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int MOD = 1000000007;
        // unordered_map<int, int> prefixCount;
        // prefixCount[0] = 1;
        // int prefixSum = 0;

        int n = nums.size();
        // vector<int> prefix(n , 0);
        int result = 0;
        // prefix[0] = nums[0];

        // for(int i = 1; i<n; i++){
        //     prefix[i] = prefix[i-1]+nums[i];
        // }

        int evenCnt = 1, oddCnt = 0;

        int sum = 0;

        for (int num : nums) {
            sum += num;
            if (sum % 2 == 1) {
                result = (result + evenCnt) % MOD;
                oddCnt++;
            } else {
                result = (result + oddCnt) % MOD;
                evenCnt++;
            }

        }

        return result;
    }
};