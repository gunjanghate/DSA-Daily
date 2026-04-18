class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int zeros = 0;
        int ans = INT_MIN;
        int i =0, j =0;
        
        while(j<nums.size()){
            if(nums[j]==0) zeros++;
            if(zeros>k){
                if(nums[i]==0) zeros--;
                i++;
            }

            if(zeros<=k){
            ans = max(ans, j - i + 1);
            }

            j++;
        }

        return ans;

    }
};