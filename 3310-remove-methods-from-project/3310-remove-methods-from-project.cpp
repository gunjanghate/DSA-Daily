class Solution {
public:
    vector<int> remainingMethods(int n, int k,
                                 vector<vector<int>>& invocations) {
        vector<vector<int>> edges(n);
        vector<int> inDegree(n, 0);
        vector<bool> sus(n);

        for (const auto& v : invocations) {
            edges[v[0]].push_back(v[1]);
            inDegree[v[1]]++;
        }

        queue<int> q;
        q.push(k);

        sus[k] = true;

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v : edges[u]) {
                inDegree[v]--;

                if (!sus[v]) {
                    q.push(v);
                    sus[v] = true;
                }
            }
        }

        bool f = true;
        vector<int> rem;

        for (int i = 0; i < n; i++) {
            if (sus[i] && inDegree[i] > 0) {
                f = false;
                break;
            } else if (!sus[i]) {
                rem.push_back(i);
            }
        }

        if (!f) {
            vector<int> allNode(n, 0);
            iota(allNode.begin(), allNode.end(), 0);
            return allNode;
        }

        return rem;
    }
};