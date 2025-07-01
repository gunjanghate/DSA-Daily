class Solution {
public:
    string finalString(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        string res = "";

        for(int i = 0; i<s.length(); i++){
            if(s[i]=='i'){
                reverse(res.begin(), res.end());
            }else{
                res += s[i];
            }
        }

        return res;
    }
};