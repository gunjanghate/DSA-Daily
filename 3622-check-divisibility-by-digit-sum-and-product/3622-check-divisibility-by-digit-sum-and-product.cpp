class Solution {
public:
    bool checkDivisibility(int n) {
        int digisum = 0;
        int digipd = 1;

        int a = n;
        while(a){
            int d = a % 10;
            digisum += d;
            digipd *= d;
            a /= 10;
        }

        int divi = digisum + digipd;
        // cout<<digisum<<" "<<digipd;

        return n % divi == 0;
        
    }
};