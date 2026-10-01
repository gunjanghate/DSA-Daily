class Solution {
public:
    bool match(char open, char close) {
        if (open == '(' && close == ')')
            return true;
        if (open == '{' && close == '}')
            return true;
        if (open == '[' && close == ']')
            return true;
        return false;
    }

    bool isValid(string exp) {
        stack<char> s;
        int n = exp.length();
        for (int i = 0; i < n; i++) {
            if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[') {
                s.push(exp[i]);
            } else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']') {
                if (s.empty())
                    return false;
                char popped_ch;
                popped_ch = s.top();
                s.pop();
                if (!match(popped_ch, exp[i]))
                    return false;
            }
        }
        return s.empty();
    }
};