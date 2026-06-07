class Solution {
public:
    bool detectCapitalUse(string word) {
        int up = 0;
        for(auto i : word){
            if(isupper(i)) up++;
        }
        if(up==1) return isupper(word[0]);
        if(up>0){
        for(auto i : word){
            if(islower(i)) return false;
        }
        }

        return true;
    }
};