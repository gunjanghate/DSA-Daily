class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_set<char> st;
        int ans = 0;
        for(int i = 0; i<word.length(); i++){
            char c  = word[i];
            if(c>='a' && c<='z'){
                if(st.find(toupper(c))!=st.end() && st.find(c)==st.end()){
                    st.insert(c);
                    ans++;
                }else{
                    st.insert(c);
                }
            }else if(c>='A' && c<='Z'){
                if(st.find(tolower(c))!=st.end() && st.find(c)==st.end()){
                    st.insert(c);
                    ans++;
                }else{
                    st.insert(c);
                }
            }
        }

        return ans;
    }
};