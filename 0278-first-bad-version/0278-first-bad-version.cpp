// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int l = 1;
        int h = n;
        int ans = INT_MAX;
        while(l<=h){
            int m = l + (h-l)/2;
            if(isBadVersion(m)){
                ans = min(ans, m);
                h = m-1;
            }else{
                l = m+1;
            }
        }

        return ans;
    }
};