class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions,
                                      vector<int>& healths,
                                      string directions) {

        int n = positions.size();
        vector<int> idx(n);
        for (int i = 0; i < n; i++) idx[i] = i;

        sort(idx.begin(), idx.end(), [&](int a, int b) {
            return positions[a] < positions[b];
        });

        stack<int> s;

        for (int id : idx) {

            while (!s.empty() &&
                   directions[s.top()] == 'R' &&
                   directions[id] == 'L') {

                int top = s.top();

                if (healths[id] > healths[top]) {
                    // current survives, stack robot dies
                    healths[top] = 0;
                    s.pop();
                    healths[id]--;
                }
                else if (healths[id] < healths[top]) {
                    // stack robot survives
                    healths[top]--;
                    healths[id] = 0;
                    break;
                }
                else {
                    // both die
                    healths[top] = 0;
                    healths[id] = 0;
                    s.pop();
                    break;
                }
            }

            // if still alive → push
            if (healths[id] > 0) {
                s.push(id);
            }
        }

        vector<int> result;
        for (int i = 0; i < n; i++) {
            if (healths[i] > 0) {
                result.push_back(healths[i]);
            }
        }

        return result;
    }
};