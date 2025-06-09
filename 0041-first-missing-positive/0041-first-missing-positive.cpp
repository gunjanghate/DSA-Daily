class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        // map<int, int> mp;
        // for(auto i : nums) mp[i]++;
        // if(!mp.count(1)){
        //     return 1;
        // }
        // int ans = INT_MAX;
        // for(int i = 0;i<nums.size(); i++){
        //     if(nums[i]<=0) continue;
        //     if(nums[i] < INT_MAX && mp.count(nums[i]) !=
        //     mp.count(nums[i]+1)){
        //         ans = min(ans,nums[i]+1);
        //     }
        // }
        // if(ans==-1) return nums.size();
        // return ans;
        // O(NLogN) :- TC
        // O(N) :- SC
        // using cyclic sort O(N) and O(1)
        int n = nums.size();

        for (int i = 0; i < n; ++i) {
            while (nums[i] >= 1 && nums[i] <= n &&
                   nums[i] != nums[nums[i] - 1]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }

        for (int i = 0; i < n; ++i) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }

        return n + 1;
    }
};