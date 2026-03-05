class Solution {
public:
    int minOperations(string s) {
        int cnt = 0;
        string s1, s2;
        int l = s.length();
        for(int i = 0; i<l; i++){
            s1 += i%2==0 ?'1': '0';
            s2 += i%2==0 ?'0': '1';
            
        }
        int cnt1 = 0, cnt2 = 0;

        for(int i = 0; i<l; i++){
            if(s[i]!=s1[i]) cnt1++;
            if(s[i]!=s2[i]) cnt2++;
        }
        
        return min(cnt1, cnt2);
    }
};