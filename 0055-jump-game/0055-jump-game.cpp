class Solution {
public:

    bool canJump(vector<int>& nums) {
     int maxIdx = 0;
     for(int i = 0; i<nums.size(); i++){
        if(i>maxIdx) return false;
        int cur = i + nums[i];
        maxIdx = max(maxIdx, cur);
     }   

     return true;
    }
};