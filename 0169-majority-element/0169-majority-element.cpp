class Solution {
public:
    int majorityElement(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int cnt = 0;
        int ele;
        for(int i = 0; i<nums.size(); i++){
            if(cnt==0){
                ele = nums[i];
                cnt++;
            }else{
                if(ele==nums[i]) cnt++;
                else cnt--;
            }
        }

        return ele;
        
    }
};