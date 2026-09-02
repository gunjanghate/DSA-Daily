class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int odd = 0, eve = 0;
        int n = nums1.size();
        if(n==1) return true;
        for(int i = 0; i<n ; i++){
            bool f  = false;
            int a = 0;
            if(nums1[i]%2!=0){
                odd++;
            }else{

            for(int j = 0; j<n; j++){
                if(i==j) continue;
                a = nums1[i] - nums1[j];

                if(a%2!=0){
                    odd++;
                    break;
                }
            }
            }
        }
        for(int i = 0; i<n ; i++){
            bool f  = false;
            int a = 0;
            if(nums1[i]%2==0){
                eve++;
            }else{

            for(int j = 0; j<n; j++){
                if(i==j) continue;
                a = nums1[i] - nums1[j];

                if(a%2==0){
                    eve++;
                    break;
                }
            }
            }
        }


        return odd = n -1 || eve == n-1;
    }
};