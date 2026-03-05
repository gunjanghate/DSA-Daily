class Solution {
public:
    int minOperations(string s) {
        int cnt1 = 0, cnt2 = 0;
        int n = s.length();

        for(int i = 0; i < n; i++){
            
            if(s[i] != (i % 2 == 0 ? '1' : '0'))
                cnt1++;

            if(s[i] != (i % 2 == 0 ? '0' : '1'))
                cnt2++;
        }

        return min(cnt1, cnt2);
    }
};