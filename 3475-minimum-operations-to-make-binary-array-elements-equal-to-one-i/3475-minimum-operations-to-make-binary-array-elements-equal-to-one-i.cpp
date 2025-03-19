class Solution {
public:
    void doFlip(int start, int end, vector<int>& nums)
    {
        for(int i = start; i<=end; i++){
            nums[i]=!nums[i];
        }
    }
    int minOperations(vector<int>& nums) {
        int cnt = 0;
        if(nums[0]==0){
            doFlip(0,2,nums);
            cnt++;
        }
        for(int i = 1; i<=nums.size()-3; i++){
            if(nums[i]==0){
                doFlip(i, i+2, nums);
                cnt++;
            }
        }
        for (auto &x : nums) {
            if (x == 0) return -1;
        }

        return cnt;
    }
};