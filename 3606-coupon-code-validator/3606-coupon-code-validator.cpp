class Solution {
public:
    bool isValid(string &s) {
        if(s.empty()) return false;
        for(char ch : s) {
            if(!isalnum(ch) && ch != '_') return false;
        }
        return true;
    }
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        vector<string> ans;
        vector<pair<string, string>> arr;
        for(int i=0; i<code.size(); i++) {
            if(isValid(code[i]) && (businessLine[i] == "electronics" || businessLine[i] == "grocery" || businessLine[i] == "pharmacy" || businessLine[i] == "restaurant") && isActive[i]){
                arr.push_back({businessLine[i], code[i]});
            }
        }
        sort(arr.begin(), arr.end());
        for(int i=0; i<arr.size(); i++) {
            ans.push_back(arr[i].second);
        }
        return ans;
    }
};