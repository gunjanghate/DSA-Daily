class Solution {
public:
    int reverseDigits(int num){
        int rev = 0;
        while(num>0){
            rev = rev*10 + num%10;
            num /= 10;
        }
        return rev;
    }
    int mirrorDistance(int n) {
        int rev = reverseDigits(n);


        return abs(rev - n);
    }
};