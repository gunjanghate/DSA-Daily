class Solution {
public:
    bool isPowerOfFour(int n) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        if(n<=0) return false;
        while(n>0){
            if(n==1) return true;
            if(n%4!=0) return false;
            n/=4;
        }

        return true;
    }
};