class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int cntL = 0;
        int cntR = 0;
        for(auto i : moves){
            if(i=='L') cntL++;
            if(i=='R') cntR++;
        }
        int under = (cntL>cntR) ? -1 : 1;
        int ans = 0;
        for(auto i : moves){
            if(i=='L') ans--;
            else if(i=='R') ans++;
            else{
                ans += under;
            }
        }

        return abs(ans);
    }
};