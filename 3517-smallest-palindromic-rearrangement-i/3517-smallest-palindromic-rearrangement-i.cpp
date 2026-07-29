class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.length();

        int count[26] = {0};

        for(int i = 0; i<n/2; i++){
            count[s[i] - 'a']++;
        }

        int idx = 0;
        for(int i = 0; i<26; i++){
            while(count[i]-- > 0){
                s[idx++] = (char) (i + 'a');
            }
        }

        for(int i = 0; i<n/2; i++){
            s[n - i - 1] = s[i];
        }


        return s;
    }
};