class Solution {
public:
    int countAsterisks(string s) {
        int noOfDash = 0;
        int noOfAst = 0;

        for(int i = 0; i<s.length(); i++){
            if(s[i]=='|') noOfDash++;
            if(noOfDash%2==0 && s[i]=='*') noOfAst++;
        }


        return noOfAst;

    }
};