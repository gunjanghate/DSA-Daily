class Solution {
public:
    void backtrack(string &num, long target, int index,
                   long currentValue, long lastNumber,
                   string expression, vector<string> &ans) {
        
        if (index == num.size()) {
            if (currentValue == target) {
                ans.push_back(expression);
            }
            return;
        }

        for (int i = index; i < num.size(); i++) {

            if (i > index && num[index] == '0') break;

            string part = num.substr(index, i - index + 1);
            long number = stol(part);

            if (index == 0) {
                backtrack(num, target, i + 1,
                          number, number,
                          part, ans);
            } else {
                // +
                backtrack(num, target, i + 1,
                          currentValue + number,
                          number,
                          expression + "+" + part, ans);

                // -
                backtrack(num, target, i + 1,
                          currentValue - number,
                          -number,
                          expression + "-" + part, ans);

                // *
                backtrack(num, target, i + 1,
                          currentValue - lastNumber + lastNumber * number,
                          lastNumber * number,
                          expression + "*" + part, ans);
            }
        }
    }

    vector<string> addOperators(string num, int target) {
        vector<string> ans;
        backtrack(num, target, 0, 0, 0, "", ans);
        return ans;
    }
};