class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int p = 0;
        int q = 0;
        bool isP = false, isQ = false, isP2 = false;
        for(int i =0; i< nums.size()-1; i++){
            if(nums[i]==nums[i+1]) return false;
            if(q==0 && nums[i]<nums[i+1]){
                p++;
                isP = true; 
            }else if(nums[i]>nums[i+1]){
                if(!isP) return false;
                if(isP2) return false;
                p = 0;
                q++;
                isQ = true;
            }
            else if(isQ && nums[i]<nums[i+1]){
                isP2 = true;
            }
        }


        if(isP && isQ && isP2) return true;


        return false;
        
    }
};