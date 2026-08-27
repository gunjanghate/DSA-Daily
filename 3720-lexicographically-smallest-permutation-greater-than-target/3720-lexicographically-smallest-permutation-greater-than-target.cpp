class Solution {
public:
    bool solve(string curr, vector<int>& freq, string target, int i, bool isGreater, string& res){
        if(i==target.length()){
            if(isGreater){
                res = curr;
                return true;
            }
            return false;
        }

        for(char ch = 'a'; ch<='z'; ch++){
            if(freq[ch-'a']==0) continue;
            if(!isGreater && ch< target[i]) continue;

            curr.push_back(ch);
            freq[ch-'a']--;

            bool g = isGreater || ch > target[i];

            if(solve(curr, freq, target, i+1, g, res)){
                return true;
            }

            curr.pop_back();
            freq[ch-'a']++;
        }

        return false;

    }
    string lexGreaterPermutation(string s, string target) {
        vector<int> freq(26, 0);

        for(auto ch : s) freq[ch-'a']++;

        string curr="";
        string res;
        
        solve(curr, freq, target, 0, false, res);

        return res;
    }
};