class Solution {
  public:
    string toggleCase(string &s) {

        for(auto &ch : s){

            if(ch >= 'A' && ch <= 'Z'){
                ch = ch + 32;
            }
            else if(ch >= 'a' && ch <= 'z'){
                ch = ch - 32;
            }

        }

        return s;
    }
};