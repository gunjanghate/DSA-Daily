class Solution {
public:
    int numberOfSubstrings(string s) {
        int lastseen[] = {-1, -1, -1};
        int cnt = 0;
        for(int i = 0; i<s.length(); i++){
            lastseen[s[i] - 'a'] = i;
            if(lastseen[0]!=-1 && lastseen[1]!=-1 && lastseen[2]!=-1){
                int mnIdx = min(lastseen[0], min(lastseen[1], lastseen[2]));
                cnt += 1 + mnIdx;
            }
        }

        return cnt;
        
    }
};