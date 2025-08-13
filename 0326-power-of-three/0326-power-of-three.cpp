class Solution {
public:
    bool isPowerOfThree(int n) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        if(n<=0) return false;
        while(n>0){
            if(n==1) return true;
            if(n%3!=0) return false;
            n/=3;
        }

        return true;
    }
};