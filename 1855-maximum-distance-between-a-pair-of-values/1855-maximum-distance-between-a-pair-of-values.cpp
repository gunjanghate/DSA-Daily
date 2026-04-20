class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {

        int ans = 0;
        for (int i = 0; i < nums1.size(); i++) {
            int curr = nums1[i];
            int r = nums2.size() - 1;
            int l = i;
            // int j = -1;
            while(l<=r){
                int m = l + (r-l)/2;
                if(nums2[m]<curr){
                    r = m - 1;
                }else if(nums2[m]>=curr){
                    // j = m;
                    l = m + 1;
                    ans = max(ans, m - i);
                }
            }
            // if(j != -1){
            // }
        }

        return ans;
    }
};