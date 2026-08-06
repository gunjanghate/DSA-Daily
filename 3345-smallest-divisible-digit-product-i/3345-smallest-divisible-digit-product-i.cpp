class Solution {
public:
    int smallestNumber(int n, int t) {
        int num = n;

        while(true){
            int prd = 1;
            n = num;
            while(n){
                prd *= n%10;
                n /= 10;
            }
            if(prd % t == 0){
                break;
            }
            else num++;
        }

        return num;
    }
};