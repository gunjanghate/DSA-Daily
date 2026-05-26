class Solution {
public:
    int numberOfSpecialChars(string word) {

        unordered_set<char> st;
        int ans = 0;

        for(char c : word){

            if(islower(c)){

                if(st.find(toupper(c)) != st.end() &&
                   st.find(c) == st.end()) {

                    ans++;
                }

                st.insert(c);
            }

            else if(isupper(c)){

                if(st.find(tolower(c)) != st.end() &&
                   st.find(c) == st.end()) {

                    ans++;
                }

                st.insert(c);
            }
        }

        return ans;
    }
};