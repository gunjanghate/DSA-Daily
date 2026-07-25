class Solution {
public:
    int maxProduct(int n) {
        int sL = INT_MIN + 1;
        int L = INT_MIN;

        while(n>0){
            int d = n % 10;

            if(d>L){
                sL = L;
                L = d;
            }else if(d>sL){
                sL = d;
            }
            n /= 10;
        }


        return sL * L;
    }
};