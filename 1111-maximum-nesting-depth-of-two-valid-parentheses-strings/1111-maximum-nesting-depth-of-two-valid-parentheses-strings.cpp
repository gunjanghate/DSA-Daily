class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        vector<int> res;
        int depth = 0;

        for (char ch : seq) {
            if (ch == '(') {
                res.push_back(depth % 2);
                depth++;
            } else {
                depth--;
                res.push_back(depth % 2); 
            }
        }

        return res;
    }
};
