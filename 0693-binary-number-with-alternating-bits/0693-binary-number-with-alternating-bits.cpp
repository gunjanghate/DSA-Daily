class Solution {
public:
    bool hasAlternatingBits(int n) {
        unsigned int x = n ^ (n >> 1);
        return (x & (x + 1)) == 0; // property for number with all 1's
    }
};