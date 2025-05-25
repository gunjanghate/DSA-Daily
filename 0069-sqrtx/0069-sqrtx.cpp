class Solution {
public:
    int mySqrt(int x) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        long long l =0;
        long long h = x;
        long long ans = -1;
        while(l<=h){
        long long m = l + (h-l)/2;
            if(m*m==x) return m;
            else if(m*m>x) h = m-1;
            else {
                ans = m;
                l = m+1;
            } 
        }

        return ans;

    }
};