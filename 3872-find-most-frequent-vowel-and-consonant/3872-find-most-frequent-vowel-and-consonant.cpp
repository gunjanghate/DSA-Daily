class Solution {
    
public:
    bool isVowel(char c){
        if(c=='a'|| c=='e'|| c=='i' || c=='o' || c=='u') return true;
        return false;
    }
    int maxFreqSum(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        map<char, int> mp1;
        map<char, int> mp2;

        for(int i = 0; i<s.length(); i++){
            if(isVowel(s[i])){
                mp1[s[i]]++;
            }else{
                mp2[s[i]]++;
            }
        }

        int mx1 = 0, mx2 = 0;

        for(auto &[i, k]: mp1){
            mx1 = max(mx1, k);
        }
        for(auto &[i, k]: mp2){
            mx2 = max(mx2, k);
        }


        return mx1+mx2;

        
    }
};