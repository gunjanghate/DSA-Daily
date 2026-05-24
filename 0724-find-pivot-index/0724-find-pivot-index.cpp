class Solution {
public:
    int rightSum(vector<int> nums, int k){
        int s = 0;
        for(int i = k; i<nums.size(); i++){
            s += nums[i];
        }

        return s;
    }
    int pivotIndex(vector<int>& nums) {
        int lsum = 0;
        for(int i = 0; i<nums.size(); i++){
            int rsum = rightSum(nums, i+1);
            if(lsum==rsum) return i;
            else lsum += nums[i];
        }

        return -1;

        
    }
};