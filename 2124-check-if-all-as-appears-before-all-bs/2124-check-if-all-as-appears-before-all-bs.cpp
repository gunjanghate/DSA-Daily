class Solution {
public:
    bool checkString(string s) {

        bool found = false;

        for(auto c : s){
            if(c=='b' && !found) found = true;
            if(c=='a' && found) return false;
        }

        return true;
        
    }
};