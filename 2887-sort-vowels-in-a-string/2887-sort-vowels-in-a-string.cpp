class Solution {
public:
    bool isVowel(char c){
        if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||c=='A'||c=='E'||c=='I'||c=='O'||c=='U'){
            return true;
        }
        return false;
    }
    string sortVowels(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        vector<char> vowels;
        for(int i = 0; i<s.length(); i++){
            if(isVowel(s[i]))
                vowels.push_back(s[i]);
        }
        sort(vowels.begin(), vowels.end());
        int k =0;

        for(int i = 0; i< s.length(); i++){
            if(isVowel(s[i])){
                s[i]=vowels[k];
                k++;
            }
        }

        return s;

        
    }
};