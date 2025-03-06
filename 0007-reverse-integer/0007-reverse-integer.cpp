class Solution {
public:
    int reverse(int x) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        long long rev = 0;
        while (x != 0) {
            int d = x % 10;
            if (rev > (INT_MAX / 10) || rev < (INT_MIN / 10)) 
                return 0;
            
            rev = rev * 10 + d; 
            x /= 10;
        }
        
        return (int)rev;
    }
};
