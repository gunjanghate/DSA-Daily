class Solution {
public:
    int possibleStringCount(string word) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int cnt =1;
        for(int i = 0; i<word.length()-1; i++){
            if(word[i]==word[i+1]){
                cnt++;
            }
        }

        return cnt;
    }
};