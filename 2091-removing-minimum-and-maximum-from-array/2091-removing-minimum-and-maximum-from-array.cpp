class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int mn = *min_element(nums.begin(), nums.end());
        int mx = *max_element(nums.begin(), nums.end());
        int n = nums.size();

        if(n==1) return 1;

        int mnIdx = 0, mxIdx = 0;
        for(int i = 0; i<n; i++){
            if(nums[i]==mn) mnIdx = i;
            if(nums[i]==mx) mxIdx = i;
        }
        cout<<mnIdx<<" "<<mxIdx<<"/n";

        int c1 = max(mnIdx, mxIdx) + 1;
        int c2 = n - min(mnIdx, mxIdx);
        int c3 = 1 + min(mnIdx, mxIdx) + n - max(mnIdx, mxIdx);
        cout<<c1<<" "<<c2<<" "<<c3;
        return min({c1, c2, c3});
         
    }
};