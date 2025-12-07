class Solution {
public:
    int countOdds(int low, int high) {
        int r = high - low + 1;
        if(r%2==0){
            return r/2;
        }else{
            if(low%2==0 && high%2==0) return (r/2);
            return (r/2) + 1;
        }

    }
};