class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> pref(n);
        int a = INT_MAX;
        for(int i = n-1; i>=0; i--){
            a = min(a, nums[i]);
            pref[i] = a; 
        }

        int b = INT_MIN;
        for(int i = 0; i<n; i++){
            b = max(b, nums[i]);
            int g = b - pref[i];

            if(g <= k){
                return i;
            }

        }

        return -1;
    }
};